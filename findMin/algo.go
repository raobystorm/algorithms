package findmin

func bsearch(n []int, l int, r int) int {
	if n[l] < n[r] || l >= r {
		return n[l]
	}
	piv := (l + r) / 2
	if n[piv] > n[r] {
		return bsearch(n, piv+1, r)
	} else {
		return bsearch(n, l, piv)
	}
}

func findMin(nums []int) int {
	return bsearch(nums, 0, len(nums)-1)
}
