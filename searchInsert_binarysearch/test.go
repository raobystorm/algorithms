package searchInsert

// SearchInsert binary search example
func SearchInsert(nums []int, target int) int {
	i := 0
	j := len(nums) - 1
	p := 0
	for i <= j {
		// keep target in (nums[i], nums[j])
		// find mid of (i, j)
		p = (i + j) / 2
		if target == nums[p] {
			return p
		} else if target > nums[p] {
			i = p + 1
		} else {
			j = p - 1
		}
	}
	return i
}
