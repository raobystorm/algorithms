package subarraysum

func subarraySum(nums []int, k int) int {
    res, sum := 0, 0
	m := make(map[int]int)
	m[0] = 1
    for i := range nums {
		sum += nums[i]
		if n, ok := m[sum - k]; ok {
			res += n
		}
		x, ok := m[sum]
		if !ok {
			x = 1
		} else {
			x++
		}
		m[sum] = x
    }
    return res
}
