
import math

def solution(indices, K):
    results = []
    step = int(math.ceil(len(indices) / K))
    tested = []
    for i in range(0, len(indices), step):
        if i < len(indices)-step:
            curr_test = indices[i:i+step]
            results.append([i for i in indices if i not in curr_test])
            results.append(curr_test)
            tested.extend(curr_test)
        else:
            last_test = [i for i in indices if i not in tested]
            last_train = [i for i in indices if i not in last_test]
            results.append(last_train)
            results.append(last_test)

    return results

print(solution([1,2,3,4,5,6], 3))