package findpeakgrid

// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

// Example 1:

// Input: mat = [
// 	[1,4],
// 	[3,2]
// ]
// Output: [0,1]
// Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

// Example 2:

// Input: mat = [
// 	[10,20,15],
// 	[21,30,14],
// 	[7,16,32]
// ]
// Output: [1,1]
// Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.

// Constraints:

//     m == mat.length
//     n == mat[i].length
//     1 <= m, n <= 500
//     1 <= mat[i][j] <= 105
//     No two adjacent cells are equal.

// 根据leetcode的hint使用二分搜索
// 先从最中间的列以及左右两边的相邻的列找到最大值
// 如果最大值在最中间的列则为peak，如果在左边，则对左半部分的矩阵重复二分搜索，否则搜索右半部分
func bsearch(m [][]int, l int, r int) []int {
	mid := (l + r) / 2
	maxI, maxJ, max := -1, -1, -1
	j := 0
	for i := range m {
		j = mid - 1
		for j <= mid+1 {
			if m[i][j] > max {
				max = m[i][j]
				maxI = i
				maxJ = j
			}
			j++
		}
	}
	if maxJ == mid {
		return []int{maxI, maxJ}
	}
	if maxJ < mid {
		return bsearch(m, l, mid)
	}
	return bsearch(m, mid, r)
}

func findPeakGrid(mat [][]int) []int {
	m := make([][]int, len(mat)+2)
	// 构造一个四周填上-1的矩阵方便处理边界
	for i := range m {
		m[i] = make([]int, len(mat[0])+2)
		for j := range m[i] {
			if i == 0 || i == len(m)-1 {
				m[i][j] = -1
				continue
			} else if j == 0 || j == len(m[i])-1 {
				m[i][j] = -1
			} else {
				m[i][j] = mat[i-1][j-1]
			}
		}
	}

	res := bsearch(m, 0, len(m[0])-1)
	res[0]--
	res[1]--
	return res
}
