package uniquepath2

func uniquePathsWithObstacles(grid [][]int) int {
	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] == 1 {
				grid[i][j] = 0
			} else if i == 0 && j == 0 {
				grid[i][j] = 1 - grid[i][j]
			} else if i == 0 {
				grid[i][j] = grid[i][j-1]
			} else if j == 0 {
				grid[i][j] = grid[i-1][j]
			} else {
				grid[i][j] = grid[i-1][j] + grid[i][j-1]
			}
		}
	}
	return grid[len(grid)-1][len(grid[0])-1]
}
