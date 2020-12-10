package maxvalue

func maxValue(grid [][]int) int {
	// prev is the last row's max
	prev := make([]int, len(grid[0]))
	// curr is the current row's max
	curr := make([]int, len(grid[0]))
	curr[0] = grid[0][0]
	for i := range grid {
		for j := range grid[i] {
			if i == 0 && j == 0 {
				continue
			} else if i == 0 {
				curr[j] = curr[j-1] + grid[0][j]
			} else if j == 0 {
				curr[0] = prev[0] + grid[i][0]
			} else {
				if prev[j] > curr[j-1] {
					curr[j] = prev[j] + grid[i][j]
				} else {
					curr[j] = curr[j-1] + grid[i][j]
				}
			}
		}
		copy(prev, curr)
	}
	return curr[len(curr)-1]
}
