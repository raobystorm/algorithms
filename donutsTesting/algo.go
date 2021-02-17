package donutstesting

func dfs(m int, n int, A [][]int, checked *[][]bool) {
	if (*checked)[m][n] {
		return
	}
	(*checked)[m][n] = true
	if m > 0 && A[m-1][n] == A[m][n] && !(*checked)[m-1][n] {
		dfs(m-1, n, A, checked)
	}
	if m < len(A)-1 && A[m+1][n] == A[m][n] && !(*checked)[m+1][n] {
		dfs(m+1, n, A, checked)
	}
	if n > 0 && A[m][n-1] == A[m][n] && !(*checked)[m][n-1] {
		dfs(m, n-1, A, checked)
	}
	if n < len(A[0])-1 && A[m][n+1] == A[m][n] && !(*checked)[m][n+1] {
		dfs(m, n+1, A, checked)
	}
}

func Solution(A [][]int) int {
	res := 0
	checked := make([][]bool, len(A))
	for i := range checked {
		checked[i] = make([]bool, len(A[0]))
	}

	for i := range A {
		for j := range A[0] {
			if !checked[i][j] {
				res++
				dfs(i, j, A, &checked)
			}
		}
	}
	return res
}
