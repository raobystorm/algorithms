import numpy as np
from typing import Tuple, List
from random import sample


def euclidean_distance(x: np.ndarray, y: np.ndarray) -> np.ndarray:
    return np.linalg.norm(x - y)


def cosine_distance(x: np.ndarray, y: np.ndarray) -> np.ndarray:
    return 1 - np.dot(x, y) / (np.linalg.norm(x) * np.linalg.norm(y))


def manhattan_distance(x: np.ndarray, y: np.ndarray) -> np.ndarray:
    return np.linalg.norm(x - y, 1)


def mean_square_error(x: np.ndarray, y: np.ndarray) -> np.ndarray:
    return np.sum((x - y) ** 2) / 2


def l2_norm(x: np.ndarray) -> np.ndarray:
    return np.linalg.norm(x)


def train_test_split(
    X: np.ndarray, y: np.ndarray, test_ratio: float = 0.1
) -> Tuple[np.ndarray, np.ndarray, np.ndarray, np.ndarray]:
    test_idxs = sample(range(X.shape[0]), test_ratio * X.shape[0])
    train_idxs = set(range(X.shape[0])) - set(test_idxs)
    return X[train_idxs, :], y[train_idxs, :], X[test_idxs, :], y[test_idxs, :]


def k_fold(
    X: np.ndarray, y: np.ndarray, k: int
) -> List[Tuple[np.ndarray, np.ndarray, np.ndarray, np.ndarray]]:
    length = X.shape[0]
    valid_size = length // k
    result = []
    for i in range(0, length - valid_size, valid_size):
        valid_idxs = list(range(i, i + valid_size))
        train_idxs = list(set(range(length)) - set(valid_idxs))
        result.append((X[train_idxs], y[train_idxs], X[valid_idxs], y[valid_idxs]))
    return result


def cross_entropy(y: np.ndarray, t: np.ndarray) -> np.ndarray:
    return -1 * (t * np.log(y) + (1 - t) * np.log(1 - y))


def logistic_func(x: np.ndarray) -> np.ndarray:
    return 1 / (1 + np.exp(-1 * x))


def class_stats(y_pred: np.ndarray, t: np.ndarray) -> Tuple[int, int, int, int]:
    assert y_pred.shape == t.shape
    tp, fp, tn, fn = 0, 0, 0, 0
    for i in range(y_pred.shape[0]):
        if y_pred[i] == 1 and t[i] == 1:
            tp += 1
        elif y_pred[i] == 1 and t[i] == 0:
            fp += 1
        elif y_pred[i] == 0 and t[i] == 1:
            fn += 1
        elif y_pred[i] == 0 and t[i] == 0:
            tn += 1

    return tp, fp, tn, fn


def precision(tp: int, fp: int) -> float:
    if tp == 0 and fp == 0:
        return 0.0
    return tp / (tp + fp)


def recall(tp: int, fn: int) -> float:
    if tp == 0 and fn == 0:
        return 0.0
    return tp / (tp + fn)


def accuracy(tp: int, fp: int, tn: int, fn: int) -> float:
    return (tp + tn) / (tp + fp + tn + fn)


def normalize(X: np.ndarray) -> np.ndarray:
    mean = np.mean(X, axis=0)
    std = np.std(X, axis=0)
    for i, _ in enumerate(X):
        X[i] -= mean
        X[i] /= std
    return X