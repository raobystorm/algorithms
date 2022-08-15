import numpy as np
from typing import List
from utils import logistic_func

def ReLU(x: np.ndarray) -> np.ndarray:
    x[x < 0] = 0
    return x
 
# x * w0 = h0, h1 = h0 * w1, y = h1 * w2, L = tlny + (1-t)ln(1-y)
# 
# d
class NeuralNetwork:
    def __init__(
        self,
        input_size: int = 64,
        network_sizes: List[int] = [128, 64],
        activation_func = ReLU,
        learning_rate: float = 0.03,
    ):
        self.weights = []
        self.hidden_units = []
        self.deltas = []
        self.input_size = input_size
        self.activation_func = activation_func
        for i in range(len(network_sizes)):
            self.hidden_units.append(np.zeros((1, network_sizes[i])))
            self.deltas.append(np.zeros((1, network_sizes[i])))
            if i > 0:
                self.weights.append(np.random.normal((network_sizes[i-1], network_sizes[i])))
            else:
                self.weights.append(np.random.normal((input_size, network_sizes[0])))
        
        self.weights.append(np.random.normal((network_sizes[-1], 1)))
        self.deltas.append(np.zeros(1, 1))
        self.output = np.zeros((1, 1))
        self.learning_rate = learning_rate


    def forward(self, x: np.ndarray) -> np.ndarray:
        x = x.reshape((1, -1))
        for i in range(len(self.network_sizes)):
            self.hidden_units[i] = self.activation_func(np.matmul(x, self.weights[i]))
 
        self.output = logistic_func(np.matmul(self.hidden_unit[-1], self.weights[-1]))
        return self.output
 
    def backward(self, t: np.ndarray) -> None:
        self.deltas[-1] = t-self.output
        for l in range(len(self.weights)-1, -1, -1):
            self.weights = 
        
 
