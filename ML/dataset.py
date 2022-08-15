import numpy as np


class BinaryClassificationDataset:
    def __init__(self) -> None:
        self.dataset = np.concatenate(
            [
                np.random.normal((10, 20), 2, size=(30, 2)),
                np.random.normal((20, 10), 2, size=(20, 2)),
            ],
            axis=0,
        )
        self.labels = np.array([0] * 30 + [1] * 20)
        self.test_data = np.concatenate(
            [
                np.random.normal((10, 20), 1.5, size=(6, 2)),
                np.random.normal((20, 10), 3, size=(7, 2)),
            ],
            axis=0,
        )
        self.test_labels = np.array([0] * 6 + [1] * 7)


class ClassificationDataset:
    def __init__(self) -> None:
        self.dataset = np.concatenate(
            [
                np.random.normal((10, 20), 2, size=(30, 2)),
                np.random.normal((20, 10), 2, size=(20, 2)),
                np.random.normal((0, 10), 3, size=(15, 2)),
            ],
            axis=0,
        )
        self.labels = np.array([0] * 30 + [1] * 20 + [2] * 15)
        self.test_data = np.concatenate(
            [
                np.random.normal((10, 20), 2, size=(2, 2)),
                np.random.normal((20, 10), 2, size=(3, 2)),
                np.random.normal((0, 10), 3, size=(5, 2)),
            ],
            axis=0,
        )
        self.test_labels = np.array([0] * 2 + [1] * 3 + [2] * 5)


class RegressionDataset:
    def __init__(self) -> None:
        self.dataset = np.linspace(-10.0, 10.0, 20)
        self.targets = (
            0.5 * self.dataset + 1 + np.random.normal(0, 0.5, self.dataset.shape[0])
        )
        self.test_data = np.linspace(11.0, 13.0, 5)
        self.test_targets = 0.5 * self.test_data + 1
