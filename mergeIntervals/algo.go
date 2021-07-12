package mergeintervals

import "sort"

// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

// 示例 1：
// 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]
// 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].

// 示例 2：
// 输入：intervals = [[1,4],[4,5]]
// 输出：[[1,5]]
// 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。

// 提示：
// 1 <= intervals.length <= 10^4
// intervals[i].length == 2
// 0 <= starti <= endi <= 10^4

// 解法：这道题只有O(NlogN)的解
// 不可能使用一元数组来表示区间点，因为无法区分 [[0,0], [1,4]] 和 [[0,0], [0,4]] 的情况
// 只能够先将区间按照开始点来排序，然后寻找当前开始点合并之后的终点
func merge(ints [][]int) [][]int {
	sort.Slice(ints, func(i int, j int) bool {
		return ints[i][0] < ints[j][0]
	})
	res := [][]int{}
	for i := 0; i < len(ints); {
		end := ints[i][1]
		j := i + 1
		for ; j < len(ints) && ints[j][0] <= end; j++ {
			if ints[j][1] > end {
				end = ints[j][1]
			}
		}
		res = append(res, []int{ints[i][0], end})
		i = j
	}
	return res
}
