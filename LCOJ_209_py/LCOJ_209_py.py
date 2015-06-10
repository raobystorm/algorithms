class Solution:
    # @param {integer} s
    # @param {integer[]} nums
    # @return {integer}
    def minSubArrayLen(self, s, nums):
        if len(nums) == 0:
            return 0;
        
        if nums[0] > s:
            return 1;
            
        sum = [len(nums)]
        min = len(nums)

        sum[0] = nums[0]
        j = -1
        for i in range(1, len(nums)):
            sum[i] = sum[i-1] + nums[i]
            if sum[i] < s:
                continue
            while (sum[i] - sum[j]) > s:
                j = j + 1
            j = j - 1
            if min > (i - j):
                min = i - j

        if sum[len(nums)-1] < s:
            return 0
        else:
            return min