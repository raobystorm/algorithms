package longestincreasingpath

func max(arr []int) int {
	maxVal := 0
	for i := range arr {
		if arr[i] > maxVal {
			maxVal = arr[i]
		}
	}
	return maxVal
}

func dfs(mat [][]int, checked [][]int, i int, j int) int {
	if checked[i][j] != -1 {
		return checked[i][j]
	}

	tmp := []int{0, 0, 0, 0}
	if i > 0 && mat[i][j] < mat[i-1][j] {
		tmp[0] = dfs(mat, checked, i-1, j)
	}
	if j > 0 && mat[i][j] < mat[i][j-1] {
		tmp[1] = dfs(mat, checked, i, j-1)
	}
	if i < len(mat)-1 && mat[i][j] < mat[i+1][j] {
		tmp[2] = dfs(mat, checked, i+1, j)
	}
	if j < len(mat[i])-1 && mat[i][j] < mat[i][j+1] {
		tmp[3] = dfs(mat, checked, i, j+1)
	}

	checked[i][j] = max(tmp) + 1
	return checked[i][j]
}

func longestIncreasingPath(mat [][]int) int {
	checked := make([][]int, len(mat))
	for i := range mat {
		checked[i] = make([]int, len(mat[i]))
		for j := range mat[i] {
			checked[i][j] = -1
		}
	}

	maxVal := 0
	tmp := 0
	for i := range mat {
		for j := range mat[i] {
			tmp = dfs(mat, checked, i, j)
			if tmp > maxVal {
				maxVal = tmp
			}
		}
	}

	return maxVal
}
