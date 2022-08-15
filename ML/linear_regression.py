from matplotlib import pyplot as plt
import numpy as np
from random import shuffle
from typing import Optional, Callable

from dataset import RegressionDataset
from utils import mean_square_error, l2_norm


class LinearRegression:
    def __init__(
        self,
        n_dim: int,
        loss: Callable = mean_square_error,
        epoch: int = 20,
        learning_rate: float = 0.03,
        regularizer: Optional[Callable] = None,
        alpha: float = 0.2,
    ):
        self.n_dim = n_dim
        self.loss = loss
        self.epoch = epoch
        self.regularizer = regularizer
        self.alpha = alpha
        self.learning_rate = learning_rate
        self.weights = np.random.random(n_dim) * 0.01
        self.bias = np.random.random() * 0.01

    def inference(self, x: np.ndarray) -> np.ndarray:
        return self.bias + np.dot(self.weights, x)

    def predict(self, X: np.ndarray) -> np.ndarray:
        preds = np.zeros(X.shape[0])
        for i in range(X.shape[0]):
            preds[i] = self.inference(X[i])
        return preds

    def fit(self, X: np.ndarray, y: np.ndarray) -> None:
        # X: [batch_size, x0, x1 …]
        # Stochastic gradient descent

        for _ in range(self.epoch):
            idxs = list(range(X.shape[0]))
            shuffle(idxs)
            losses = []
            for idx in idxs:
                y_pred = self.inference(X[idx])
                loss = self.loss(y_pred, y[idx])
                if self.regularizer is not None:
                    loss += self.regularizer(self.weights)
                losses.append(loss)
                # L = ½*(wi*xi + b - y)^2 + alpha/2*wi^2, dL / dwi = (xi*wi+b-y)xi+alpha*wi
                self.weights -= self.learning_rate * (y_pred - y[idx]) * X[idx]
                if self.regularizer == l2_norm:
                    self.weights -= self.alpha * self.weights
                self.bias -= self.learning_rate * (y_pred - y[idx])


dataset = RegressionDataset()
lr = LinearRegression(1, mean_square_error, 20, 0.01)
lr.fit(dataset.dataset, dataset.targets)

preds = lr.predict(dataset.test_data)

for i in range(len(dataset.dataset)):
    plt.scatter(dataset.dataset[i], dataset.targets[i], marker="x", color="b")

for i in range(len(dataset.test_data)):
    plt.scatter(dataset.test_data[i], preds[i], marker="o", color="r")

print(
    f"preds = {preds}, targets = {dataset.test_targets}, MSE = {mean_square_error(preds, dataset.test_targets)}"
)

plt.show()