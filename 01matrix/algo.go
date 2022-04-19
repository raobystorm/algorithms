package o1matrix

// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

// Example 1:

// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]

// Example 2:

// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]

// Constraints:

//     m == mat.length
//     n == mat[i].length
//     1 <= m, n <= 104
//     1 <= m * n <= 104
//     mat[i][j] is either 0 or 1.
//     There is at least one 0 in mat.

func min(a int, b int) int {
	if a > b {
		return b
	}
	return a
}

// DP, scan twice. From left up corner to right down corner.
func updateMatrix(mat [][]int) [][]int {
	res := make([][]int, len(mat))
	for i := range res {
		res[i] = make([]int, len(mat[0]))
		for j := range res[0] {
			if mat[i][j] == 0 {
				res[i][j] = 0
			} else {
				res[i][j] = 10001
			}
		}
	}

	for i := len(mat) - 1; i >= 0; i-- {
		for j := len(mat[0]) - 1; j >= 0; j-- {
			if i-1 >= 0 {
				res[i-1][j] = min(res[i][j]+1, res[i-1][j])
			}
			if j-1 >= 0 {
				res[i][j-1] = min(res[i][j]+1, res[i][j-1])
			}
		}
	}

	for i := 0; i < len(mat); i++ {
		for j := 0; j < len(mat[0]); j++ {
			if i+1 < len(mat) {
				res[i+1][j] = min(res[i][j]+1, res[i+1][j])
			}
			if j+1 < len(mat[0]) {
				res[i][j+1] = min(res[i][j]+1, res[i][j+1])
			}
		}
	}

	return res
}
