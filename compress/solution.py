from typing import List, Dict

# Given an array of unique integers, "compress" it so minimum number become 1 and keep the largest number as small as possible.
# Compress rule: for A[i] < A[j], after compress still keep A[i] < A[j]

# e.g. [100, 20, 22, 30]


def compress(arr: List[int]) -> List[int]:
    sorted_dict = {i: idx + 1 for idx, i in enumerate(sorted(arr))}
    result = []
    for i in arr:
        result.append(sorted_dict[i])

    return result


# Follow up: what if there is duplicates in the array?
# Compress rule: if A[i] == A[j], after compress still keep A[i] == A[j]


def compress_with_dups(arr: List[int]) -> List[int]:
    sorted_dict: Dict[int, int] = {}
    idx = 1
    for i in sorted(arr):
        if i in sorted_dict:
            continue
        else:
            sorted_dict[i] = idx
        idx += 1

    result = []
    for i in arr:
        result.append(sorted_dict[i])

    return result


print(compress_with_dups([100, 100, 100, 100]))