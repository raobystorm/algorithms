package maximumtoys

import "sort"

func MaximumToys(prices []int, k int) int {
	sort.IntSlice(prices).Sort()
	cnt := 0
	for _, p := range prices {
		if k >= p {
			k -= p
			cnt += 1
		} else {
			return cnt
		}
	}
	return cnt
}
