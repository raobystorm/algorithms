package robii

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func rob1(nums []int) int {
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

func rob(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	if len(nums) == 1 {
		return nums[0]
	}

	// Use rob1 to calc, cyclical means nums[0], nums[1] could only have one
	return max(rob1(nums[1:]), rob1(nums[:len(nums)-1]))
}
