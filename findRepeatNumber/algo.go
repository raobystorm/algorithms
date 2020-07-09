package findrepeatnumber

// Hash, O(n) Space, O(n) time
func FindRepeatNumber(nums []int) int {
	exist := make(map[int]bool)
	for i := range nums {
		if _, ok := exist[nums[i]]; ok {
			return nums[i]
		}
		exist[nums[i]] = true
	}
	return 0
}

// Swap, O(1) Space,
func findRepeatNumber(nums []int) int {
	for i := range nums {
		if nums[nums[i]] == nums[i] && nums[i] != i {
			return nums[i]
		}
		nums[i], nums[nums[i]] = nums[nums[i]], nums[i]
	}
	return 0
}
