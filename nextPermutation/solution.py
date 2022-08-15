from typing import List


def reverse(l: List[int], i: int, j: int) -> None:
    while i < j:
        l[i], l[j] = l[j], l[i]
        i += 1
        j -= 1


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        i = len(nums) - 2
        while i >= 0:
            if nums[i] < nums[i + 1]:
                break
            i -= 1

        if i == -1:
            reverse(nums, 0, len(nums) - 1)
            return

        j = i + 1
        while j < len(nums) and nums[j] > nums[i]:
            j += 1

        j -= 1
        nums[i], nums[j] = nums[j], nums[i]
        reverse(nums, i + 1, len(nums) - 1)
