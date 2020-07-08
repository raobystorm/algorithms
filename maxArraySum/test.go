package maxarraysum

func maxInt(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// MaxSubsetSum .
func MaxSubsetSum(arr []int) int {
	if len(arr) == 1 {
		return arr[0]
	}
	if len(arr) == 2 {
		return maxInt(arr[0], arr[1])
	}
	max := [100000]int{}
	// maxSum = max till arr[i-1]
	maxSum := maxInt(arr[0], arr[1])
	max[0], max[1] = arr[0], maxSum
	for i := 2; i < len(arr); i++ {
		maxSum = maxInt(maxSum, max[i-2]+arr[i])
		maxSum = maxInt(maxSum, arr[i])
		max[i] = maxSum
	}
	return max[len(arr)-1]
}
