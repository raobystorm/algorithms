package lengthoflis

func bSearch(nums []int, n int) int {
	// Find idx of the first elem larger than n
	if len(nums) == 0 {
		return 0
	}
	// i, j = unsearched range
	i, j := 0, len(nums)
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
