package twosumhash

func twoSum(n []int, t int) []int {
	m := make(map[int]int)
	for i := range n {
		if idx, ok := m[n[i]]; ok {
			return []int{idx, i}
		}
		m[t - n[i]] = i
	}
	return []int{}
}
