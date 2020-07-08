package removeDuplicates

func RemoveDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	i := 0
	for j := 1; j < len(nums); {
		if nums[j] == nums[i] {
			j++
			continue
		}
		i++
		nums[i] = nums[j]
	}
	return i + 1
}
