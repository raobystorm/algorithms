from functools import cmp_to_key
from typing import List

# You are given an array of points in the X-Y plane points where points[i] = [xi, yi].

# Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.

# Example 1:

# Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
# Output: 4

# Example 2:

# Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
# Output: 2

# Constraints:

#     1 <= points.length <= 500
#     points[i].length == 2
#     0 <= xi, yi <= 4 * 104
#     All the given points are unique.


def cmp(x, y):
    if x[0] != y[0]:
        return x[0] - y[0]
    return x[1] - y[1]

# O(n^2) solution is ok
# iterate through all left bottom points and upper right points
class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        if len(points) < 4:
            return 0

        points = sorted(points, key=cmp_to_key(cmp))
        check = set()
        for x, y in points:
            check.add((x, y))

        res = 1600000001
        for i, (x, y) in enumerate(points):
            for j in range(i + 1, len(points)):
                j_x, j_y = points[j]
                if j_x == x or j_y == y:
                    continue
                if ((j_x, y) not in check) or ((x, j_y) not in check):
                    continue
                res = min(res, abs((j_x - x) * (j_y - y)))

        if res == 1600000001:
            return 0
        return res