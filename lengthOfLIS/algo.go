package lengthoflis

// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

// 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

//
// 示例 1：

// 输入：nums = [10,9,2,5,3,7,101,18]
// 输出：4
// 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
// 示例 2：

// 输入：nums = [0,1,0,3,2,3]
// 输出：4
// 示例 3：

// 输入：nums = [7,7,7,7,7,7,7]
// 输出：1
//

// 提示：

// 1 <= nums.length <= 2500
// -10^4 <= nums[i] <= 10^4
//

// 进阶：
// 你能将算法的时间复杂度降低到 O(n log(n)) 吗?

func bSearch(nums []int, n int) int {
	// Find idx of the first elem larger than n
	if len(nums) == 0 {
		return 0
	}
	// i, j = unsearched range
	i, j := 0, len(nums) // because we want to search first larger than t, it could be a non-exist index
	for i < j {
		piv := (i + j) / 2
		if nums[piv] < n {
			// Keep i~j as unsearched: searched part is guaranteed less than n
			i = piv + 1
		} else {
			j = piv
		}
	}
	return i
}

func lengthOfLIS(nums []int) int {
	dp := []int{}
	for _, num := range nums {
		// Find the first elem larger than num
		// if that elem is not exist, append num to the tail
		// otherwise change that elem to num. (keep the current longest increasing sub sequence)
		i := bSearch(dp, num)
		if i == len(dp) {
			dp = append(dp, num)
		} else {
			dp[i] = num
		}
	}
	return len(dp)
}
