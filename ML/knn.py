from typing import Callable
import matplotlib.pyplot as plt
from dataset import ClassificationDataset
from utils import euclidean_distance
import numpy as np


class KNN:
    def __init__(
        self,
        k: int,
        dist_func: Callable,
        objective: str = "classification",
    ) -> None:
        self.k = k
        self.objective = objective
        self.dist_func = dist_func

    def fit(self, x: np.ndarray, y: np.ndarray) -> np.ndarray:
        self.dataset = x
        self.labels = y

    def predict(self, X: np.ndarray) -> np.ndarray:
        predicts = []
        for x in X:
            distances = [
                (self.dist_func(x0, x), self.labels[i])
                for i, x0 in enumerate(self.dataset)
            ]
            neighbors = sorted(distances, key=lambda x: x[0])[: self.k]
            labels = [neighbor[1] for neighbor in neighbors]
            if self.objective == "regression":
                predicts.append(sum(labels) / len(labels))
            if self.objective == "classification":
                predicts.append(max(labels, key=labels.count))

        return np.array(predicts)


dataset = ClassificationDataset()

knn = KNN(
    10,
    euclidean_distance,
)

knn.fit(dataset.dataset, dataset.labels)

predicts = knn.predict(dataset.test_data)

markers = ["+", "*", "o"]
colors = ["r", "b", "g"]
for i in range(3):
    p = dataset.dataset[np.array(dataset.labels) == i]
    plt.scatter(p[:, 0], p[:, 1], marker=markers[i], color=colors[i])
    test = dataset.test_data[predicts == i]
    plt.scatter(test[:, 0], test[:, 1], marker="x", color=colors[i])
plt.show()