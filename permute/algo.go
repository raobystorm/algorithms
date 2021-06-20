package permute

func permute(nums []int) [][]int {
	if len(nums) == 0 {
		return [][]int{}
	}
	if len(nums) == 1 {
		return [][]int{{nums[0]}}
	}

	res := [][]int{}
	curr := permute(nums[1:])
	for j := range curr {
		for k := range curr[j] {
			newArr := make([]int, len(curr[j])+1)
			m := 0
			for m < k {
				newArr[m] = curr[j][m]
				m++
			}
			newArr[m] = nums[0]
			for m < len(curr[j]) {
				newArr[m+1] = curr[j][m]
				m++
			}
			res = append(res, newArr)
		}
		res = append(res, append(curr[j], nums[0]))
	}
	return res
}
