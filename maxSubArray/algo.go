package maxsubarray

func maxSubArray(nums []int) int {
	if len(nums) == 1 {
		return nums[0]
	}

	sum := nums[0]
	max := sum
	i := 1
	for i < len(nums) {
		if sum < 0 {
			// if previous sum is negative, just start a new sub sequence
			sum = nums[i]
		} else {
			// otherwise add sum up
			sum += nums[i]
		}
		// update max if sum is larger
		if sum > max {
			max = sum
		}
		i++
	}
	return max
}
