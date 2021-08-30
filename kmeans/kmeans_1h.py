from copy import deepcopy
from random import sample
from typing import Tuple

import matplotlib.pyplot as plt
import numpy as np


class KMeans:
    def __init__(
        self,
        n_clus: int,
        max_iter: int = 300
    ):
        # max_iter == -1 means loop until converge
        assert max_iter >= -1
        self.n_clus = n_clus
        self.max_iter = max_iter
        self.nodes: np.ndarray = None
        # save cluster ids for each node
        self.clu_ids: np.ndarray = None
        # save cluster centeroids coordinates
        self.clu_centers: np.ndarray = None

    def _update_clu_ids(self):
        """According to current cluster centeroids, update the label for each node."""
        dists = [self.clu_centers - node for node in self.nodes]
        dists = np.array(list(map(lambda x: np.linalg.norm(x, axis=1), dists)))
        self.clu_ids = dists.argmin(axis=1)

    def _calc_clu_centers(self):
        """According to each node's label, update the centeroids of clusters."""
        for i, _ in enumerate(self.clu_centers):
            idxs = np.where(self.clu_ids == i)[0]
            nodes = self.nodes[idxs]
            self.clu_centers[i] = np.mean(nodes, axis=0)

    def fit(self, X: np.ndarray) -> Tuple[np.ndarray, np.ndarray]:
        """Train KMeans model with input X. returns (labels, centeroids cordinate)"""
        assert len(X.shape) == 2 and X.shape[1] == 2
        assert X.shape[0] >= self.n_clus

        # Initialize with random nodes as centeroid
        self.nodes = X
        self.clu_centers = self.nodes[sample(
            range(self.nodes.shape[0]), self.n_clus)]

        n_iter = 0
        prev_centers = deepcopy(self.clu_centers)
        while n_iter != self.max_iter:
            # update idx for each node
            self._update_clu_ids()
            self._calc_clu_centers()
            # if converge, stop the loop
            if min(np.linalg.norm(prev_centers - self.clu_centers, axis=1)) < 1e-6:
                break
            prev_centers[:] = self.clu_centers[:]
            n_iter += 1

        return self.clu_ids, self.clu_centers


dataset = np.concatenate((
    np.random.normal(10, 6, size=(50, 2)),
    np.random.normal(50, 7, size=(50, 2)),
    np.random.normal(80, 4, size=(50, 2)),
), axis=0)

kmeans = KMeans(3, -1)
kmeans.fit(dataset)

markers = ["+", "*", "o"]
colors = ['r', 'b', 'g']
for i in range(3):
    p = dataset[kmeans.clu_ids == i]
    plt.scatter(p[:, 0], p[:, 1], marker=markers[i], color=colors[i])
plt.show()
