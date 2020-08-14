package reversepairs

func mergeSort(n *[]int, l int, r int) int {
	if l == r {
		return 0
	}

	p := (l + r) / 2
	lCnt := mergeSort(n, l, p)
	rCnt := mergeSort(n, p+1, r)

	cnt := lCnt + rCnt
	i := 0
	lIdx := l
	rIdx := p + 1
	res := make([]int, r-l+1)
	for i < len(res) {
		if rIdx <= r && lIdx <= p && (*n)[rIdx] < (*n)[lIdx] {
			// When elem in left is larger than right, there is reverse pairs
			cnt += p - lIdx + 1
			res[i] = (*n)[rIdx]
			rIdx++
		} else if lIdx <= p {
			// If elem in left is smaller than right
			res[i] = (*n)[lIdx]
			lIdx++
		} else if rIdx <= r {
			// deal with remaining elem in right
			res[i] = (*n)[rIdx]
			rIdx++
		}
		i++
	}
	copy((*n)[l:r+1], res)
	return cnt
}

func ReversePairs(nums []int) int {
	if len(nums) < 1 {
		return 0
	}
	cnt := mergeSort(&nums, 0, len(nums)-1)
	return cnt
}
