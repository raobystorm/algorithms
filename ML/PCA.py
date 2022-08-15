from math import tan
from typing import Optional
from matplotlib import pyplot as plt
import numpy as np
from utils import normalize


class PCA:
    def __init__(
        self,
        k: int = 10,
    ):
        self.k = k
        self.eigen_val = np.zeros(k)
        self.eigen_vec: Optional[np.ndarray] = None

    def fit(self, X: np.ndarray) -> np.ndarray:
        X = normalize(X)
        cov = np.transpose(X) @ X / X.shape[0]
        self.eigen_val, self.eigen_vec = np.linalg.eig(cov)
        indices = np.argsort(self.eigen_val)[::-1]
        self.eigen_vec = self.eigen_vec[:, indices]
        self.eigen_vec = self.eigen_vec[:, : self.k]
        return X @ self.eigen_vec


dataset = np.random.normal((0, 0), (1, 0.1), size=(30, 2))
for i in range(dataset.shape[0]):
    dataset[i, 1] += tan(dataset[i, 0])
plt.scatter(dataset[:, 0], dataset[:, 1], marker="x", color="b")

result = PCA(1).fit(dataset)

plt.scatter(result[:, 0], np.zeros(len(result)), marker="o", color="r")

plt.show()