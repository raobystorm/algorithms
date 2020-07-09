package findrepeatnumber

// Hash, O(n) Space, O(n) time
func FindRepeatNumber(nums []int) int {
	st := make(map[int]bool)
	 i := range nums {
		ok := exist[nums[i]]; ok {
			ms[i]
		
		nums[i]] = true
	
	urn 0
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

