# You are given an m x n binary matrix grid.
# In one operation, you can choose any row or column and flip each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
# Return true if it is possible to remove all 1's from grid using any number of operations or false otherwise.

# Example 1:
# Input: grid = [[0,1,0],[1,0,1],[0,1,0]]
# Output: true
# Explanation: One possible way to remove all 1's from grid is to:
# - Flip the middle row
# - Flip the middle column

# Example 2:
# Input: grid = [[1,1,0],[0,0,0],[0,0,0]]
# Output: false
# Explanation: It is impossible to remove all 1's from grid.

# Example 3:
# Input: grid = [[0]]
# Output: true
# Explanation: There are no 1's in grid.


# Constraints:
# m == grid.length
# n == grid[i].length
# 1 <= m, n <= 300
# grid[i][j] is either 0 or 1.

from typing import List

# Here is the hint: flip a row or a column twice will have no effect, so at most flip only once for a row or a column.
# If a grid could be all zeros finally, then after flipping all columns,
# there should be all 1 or 0 at a single row.
class Solution:
    def removeOnes(self, grid: List[List[int]]) -> bool:
        for j in range(0, len(grid[0])):
            if grid[0][j] == 1:
                for i in range(0, len(grid)):
                    grid[i][j] = 1 - grid[i][j]

        for row in grid:
            for col in range(1, len(row)):
                if row[col] != row[0]:
                    return False

        return True