package firstmissingpositive

func firstMissingPositive(nums []int) int {
	for i := 0; i < len(nums); i++ {
		// 当
		for nums[i] != i+1 &&
			nums[i] <= len(nums) &&
			nums[i] > 0 &&
			nums[i] != nums[nums[i]-1] {
			nums[i], nums[nums[i]-1] = nums[nums[i]-1], nums[i]
		}
	}

	i := 0
	for i < len(nums) {
		if nums[i] != i+1 {
			return i + 1
		}
		i++
	}
	return i + 1
}
