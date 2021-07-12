package binsearch

// This package is a collection of different binary search

// Recursive solution: for t exists in n, n is sorted
func bSearch1(n []int, t int, l int, r int) int {
	if l >= r {
		return l
	}
	piv := (l + r) / 2
	if n[piv] == t {
		return piv
	}
	if n[piv] < t {
		return bSearch1(n, t, piv+1, r)
	}
	return bSearch1(n, t, l, piv-1)
}

// Same with bSearch1 but in for loop structure
func bSearch2(n []int, t int) int {
	i, j := 0, len(n)-1
	for i < j {
		piv := (i + j) / 2
		if n[piv] == t {
			return piv
		}
		if n[piv] < t {
			i = piv + 1
		} else {
			j = piv - 1
		}
	}
	return i
}

// For t may not exist in n, find largest idx equal or less than t
func bSearch3(n []int, t int) int {
	i, j := 0, len(n)
	res := 0
	for i <= j {
		piv := (i + j) / 2
		if piv >= len(n) {
			break
		}
		if n[piv] == t {
			return piv
		} else if n[piv] < t {
			i = piv + 1
			res = piv // Save last smaller idx before stop
		} else {
			j = piv - 1
		}
	}
	return res
}

// Like bSearch3 but find insert location for t
// result could be larger than len(n). This is also official impl for golang's search
func bSearch4(n []int, t int) int {
	i, j := 0, len(n)
	for i < j {
		piv := (i + j) / 2
		if n[piv] < t {
			i = piv + 1
		} else {
			j = piv
		}
	}
	return i
}
