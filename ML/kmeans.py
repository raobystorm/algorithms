import numpy as np
from typing import Callable
import matplotlib.pyplot as plt
from dataset import ClassificationDataset
from utils import euclidean_distance


class KMeans:
    def __init__(self, k: int, iterations: int, dist_func: Callable) -> None:
        self.k = k
        self.iterations = iterations
        self.dist_func = dist_func

    def fit(self, dataset: np.ndarray) -> None:
        # dataset shape: [batch_size, x0, x1, …]
        batch_size = dataset.shape[0]
        idxs = np.random.choice(batch_size, self.k, replace=False)
        self.centroids = [dataset[idx] for idx in idxs]
        self.labels = [0] * batch_size
        for _ in range(self.iterations):
            for i, sample in enumerate(dataset):
                distances = [
                    self.dist_func(sample, centroid) for centroid in self.centroids
                ]
                self.labels[i] = np.argmin(distances)

            for i in range(len(self.centroids)):
                samples_idxs = np.where(np.array(self.labels) == i)
                self.centroids[i] = np.mean(dataset[samples_idxs], axis=0)

        self.labels = np.array(self.labels)

    def predict(self, inputs: np.ndarray) -> np.ndarray:
        labels = []
        for x in inputs:
            distances = [self.dist_func(x, centroid) for centroid in self.centroids]
            labels.append(np.argmin(distances))
        return np.array(labels)


dataset = ClassificationDataset()

kmeans = KMeans(3, 300, euclidean_distance)
kmeans.fit(dataset.dataset)
results = kmeans.predict(dataset.test_data)

markers = ["+", "*", "o"]
colors = ["r", "b", "g"]
for i in range(3):
    p = dataset.dataset[kmeans.labels == i]
    plt.scatter(p[:, 0], p[:, 1], marker=markers[i], color=colors[i])
    test = dataset.test_data[results == i]
    plt.scatter(test[:, 0], test[:, 1], marker="x", color=colors[i])
plt.show()