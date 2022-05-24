# Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

# Example 1:

# Input: intervals = [[0,30],[5,10],[15,20]]
# Output: 2

# Example 2:

# Input: intervals = [[7,10],[2,4]]
# Output: 1

# Constraints:

#     1 <= intervals.length <= 104
#     0 <= starti < endi <= 106

# We need only add current number when meets a start time, and subtract when meets an end time.
# Sort the interval starts and ends then iterate through the list.
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        starts = sorted([x[0] for x in intervals])
        ends = sorted([x[1] for x in intervals])

        i, j = 0, 0
        res, curr = 0, 0
        while i < len(starts) and j < len(ends):
            if starts[i] < ends[j]:
                curr += 1
                res = max(res, curr)
                i += 1
            else:
                curr -= 1
                j += 1

        return res
