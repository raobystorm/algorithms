package numislands

// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

// 此外，你可以假设该网格的四条边均被水包围。

//

// 示例 1：

// 输入：grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// 输出：1
// 示例 2：

// 输入：grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// 输出：3
//

// 提示：

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] 的值为 '0' 或 '1'

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/number-of-islands
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

func dfs(m [][]bool, i int, j int, grid [][]byte) {
	if m[i][j] || grid[i][j] == '0' {
		return
	}

	m[i][j] = true
	if i > 0 {
		dfs(m, i-1, j, grid)
	}
	if i < len(grid)-1 {
		dfs(m, i+1, j, grid)
	}
	if j > 0 {
		dfs(m, i, j-1, grid)
	}
	if j < len(grid[0])-1 {
		dfs(m, i, j+1, grid)
	}
}

func bfs(m [][]bool, i int, j int, grid [][]byte) {
	q := [][]int{{i, j}}
	var curr []int
	for len(q) > 0 {
		curr, q = q[0], q[1:]
		if m[curr[0]][curr[1]] {
			continue
		}

		m[curr[0]][curr[1]] = true
		if curr[0] > 0 && grid[curr[0]-1][curr[1]] == '1' {
			q = append(q, []int{curr[0] - 1, curr[1]})
		}
		if curr[0] < len(grid)-1 && grid[curr[0]+1][curr[1]] == '1' {
			q = append(q, []int{curr[0] + 1, curr[1]})
		}
		if curr[1] > 0 && grid[curr[0]][curr[1]-1] == '1' {
			q = append(q, []int{curr[0], curr[1] - 1})
		}
		if curr[1] < len(grid[0])-1 && grid[curr[0]][curr[1]+1] == '1' {
			q = append(q, []int{curr[0], curr[1] + 1})
		}
	}
}

func numIslands(grid [][]byte) int {
	res := 0
	m := make([][]bool, len(grid))
	for i := range m {
		m[i] = make([]bool, len(grid[0]))
	}

	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] == '0' {
				continue
			}
			if !m[i][j] {
				res++
				dfs(m, i, j, grid)
				// bfs(m, i, j, grid)
			}
		}
	}

	return res
}
