# Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

# Example 1:
# Input: nums = [1,1,2]
# Output:
# [[1,1,2],
#  [1,2,1],
#  [2,1,1]]

# Example 2:
# Input: nums = [1,2,3]
# Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

# Constraints:
#     1 <= nums.length <= 8
#     -10 <= nums[i] <= 10

from typing import List, Dict

# Use dp to find all sub permutations.
# 1. Build a hashmap to count all numbers and frequeces.
#      E.g. if we have {1:2, 2:2, 3:1} as frequence table
# 2. Loop through the length of original list. take one slot out and find all possible choices.
#    Concate the chosen number with the rest of the frequency table.
#      E.g. permute({1:2, 2:2, 3:1}) = {
#          1 + permute({1:1, 2:2, 3:1}),
#          2 + permute({1:2, 2:1, 3:1}),
#          3 + permute({1:2, 2:2, 3:0}),
#      }
# 3. When all counts of current frequency table is 0, we have a permutation.
class Solution:
    def permute(self, prefix: List[int], remaining: int):
        if remaining == 0:
            self.result.append(prefix.copy())
            return

        for c, cnt in self.hashmap.items():
            if cnt > 0:
                self.hashmap[c] = cnt - 1
                prefix.append(c)
                self.permute(prefix, remaining - 1)
                prefix.pop(-1)
                self.hashmap[c] = cnt

    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        self.hashmap: Dict[int, int] = {}
        for num in nums:
            if num not in self.hashmap:
                self.hashmap[num] = 0
            self.hashmap[num] += 1
        self.result: List[List[int]] = []
        self.permute([], len(nums))

        return self.result
