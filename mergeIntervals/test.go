package mergeIntervals

import "sort"

func Merge(intervals [][]int) [][]int {
	sort.Slice(intervals, func(i int, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	res := [][]int{}
	for i := 0; i < len(intervals); {
		end := intervals[i][1]
		j := i + 1
		for ; j < len(intervals) && intervals[j][0] <= end; j++ {
			if intervals[j][1] > end {
				end = intervals[j][1]
			}
		}
		res = append(res, []int{intervals[i][0], end})
		i = j
	}
	return res
}
