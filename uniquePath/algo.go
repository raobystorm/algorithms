package uniquepath

func uniquePaths(m int, n int) int {
	mat := make([][]int, m)
	for i := range mat {
		mat[i] = make([]int, n)
		mat[i][0] = 1
		for j := range mat[i] {
			if i == 0 || j == 0 {
				mat[i][j] = 1
			} else {
				mat[i][j] = mat[i-1][j] + mat[i][j-1]
			}
		}
	}
	return mat[m-1][n-1]
}
