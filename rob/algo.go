package rob

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func rob(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	if len(nums) == 1 {
		return nums[0]
	}

	prev := nums[0]
	curr := max(nums[0], nums[1])

	i := 2
	for i < len(nums) {
		curr, prev = max(prev+nums[i], curr), curr
		i++
	}
	return curr
}
