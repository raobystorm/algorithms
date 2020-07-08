package insertInterval

import "fmt"

// Binary search a number n in interval list inters.
// returns the index of interval that is just less than n

func bsearch(ints [][]int, k int) int {
	if k < ints[0][0] {
		return -1
	}
	i := 0
	j := len(ints) - 1
	if k > ints[j][1] {
		return len(ints) - 1
	}
	for i <= j {
		if ints[i][0] <= k && ints[i][1] >= k {
			return i
		}
		if ints[j][0] <= k && ints[j][1] >= k {
			return j
		}
		p := (i + j) / 2
		if ints[p][0] <= k && ints[p][1] >= k {
			return p
		}
		if ints[p][0] > k {
			j = p - 1
		} else if ints[p][1] < k {
			i = p + 1
		}
	}
	return i
}

func Insert(intervals [][]int, newInterval []int) [][]int {
	a, b := newInterval[0], newInterval[1]
	left := bsearch(intervals, a)
	right := bsearch(intervals, b)
	fmt.Println(intervals[left])
	fmt.Println(intervals[right])
	// |--a-| ... |--b-|
	if a <= intervals[left][1] && b <= intervals[right][1] {
		intervals[left][1] = intervals[right][1]
		return append(intervals[:left], intervals[right:]...)
	}
	// |--a-| ... |---| b |---|
	if a <= intervals[left][1] && b > intervals[right][1] {
		intervals[left][1] = b
		return append(intervals[:left], intervals[right:]...)
	}
	// |---| a ... |--b-|
	if a > intervals[left][1] && b <= intervals[right][1] {
		intervals[right][0] = a
		return append(intervals[:left], intervals[right:]...)
	}
	// |---| a ... |---| b |---|
	if a > intervals[left][1] && b > intervals[right][1] {
		intervals[right] = []int{a, b}
		return append(intervals[:left], intervals[right:]...)
	}
	panic("should not be here")
}
