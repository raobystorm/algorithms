from typing import Callable, List, Optional, Tuple
from matplotlib import pyplot as plt
import numpy as np
from torch import threshold
from utils import accuracy
from dataset import BinaryClassificationDataset
from utils import k_fold, precision, recall, cross_entropy, logistic_func, class_stats
from random import shuffle


class LogisticRegression:
    def __init__(
        self,
        n_dim: int,
        epoch: int,
        k: int = 10,
        threshold: float = 0.5,
        learning_rate: float = 0.03,
        regularizer: Optional[Callable] = None,
    ):
        self.weights = np.random.random(n_dim) / 100
        self.bias = np.random.random() / 100
        self.epoch = epoch
        self.k = k
        self.threshold = threshold
        self.learning_rate = learning_rate
        self.regularizer = regularizer

    def inference(self, x: np.ndarray) -> np.ndarray:
        return logistic_func(np.sum(np.dot(self.weights, x)) + self.bias)

    def predict(self, X: np.ndarray) -> np.ndarray:
        preds = np.zeros(X.shape[0])
        for i in range(X.shape[0]):
            preds[i] = self.inference(X[i])
        preds[preds >= self.threshold] = 1.0
        preds[preds < self.threshold] = 0.0
        return preds

    def evaluate(self, epoch: int, x: np.ndarray, y: np.ndarray, losses: List) -> None:
        y_preds = self.predict(x)
        tp, fp, _, fn = class_stats(y_preds, y)
        print(
            f"epoch = {epoch}, average loss = {np.mean(losses)}, precision = {precision(tp, fp)}, recall = {recall(tp, fn)}"
        )

    def fit(self, X: np.ndarray, t: np.ndarray) -> None:
        for i in range(self.epoch // self.k):
            for train_x, train_y, val_x, val_y in k_fold(X, t, self.k):
                losses = []
                train_idxs = list(range(len(train_x)))
                shuffle(train_idxs)
                for idx in train_idxs:
                    y_pred = self.inference(train_x[idx])
                    loss = cross_entropy(y_pred, train_y[idx])
                    losses.append(loss)
                    self.weights -= (
                        self.learning_rate * (y_pred - train_y[idx]) * train_x[idx]
                    )
                    self.bias -= self.learning_rate * (y_pred - train_y[idx])

                self.evaluate(i, val_x, val_y, losses)


dataset = BinaryClassificationDataset()
lr = LogisticRegression(2, 50)
lr.fit(dataset.dataset, dataset.labels)

preds = lr.predict(dataset.test_data)

markers = ["+", "*", "o"]
colors = ["r", "b", "g"]
for i in range(2):
    p = dataset.dataset[dataset.labels == i]
    plt.scatter(p[:, 0], p[:, 1], marker=markers[i], color=colors[i])
    test = dataset.test_data[preds == i]
    plt.scatter(test[:, 0], test[:, 1], marker="x", color=colors[i])

tp, fp, tn, fn = class_stats(preds, dataset.test_labels)

print(
    f"test accuracy = {accuracy(tp, fp, tn, fn)}, precision = {precision(tp, fp)}, recall = {recall(tp, fn)}"
)
plt.show()