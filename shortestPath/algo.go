package shortestpath

import "fmt"

/*
You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

Example 1:

Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation:
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).

Example 2:

Input: grid = [[0,1,1],[1,1,1],[1,0,0]], k = 1
Output: -1
Explanation: We need to eliminate at least two obstacles to find such a walk.


Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 40
    1 <= k <= m * n
    grid[i][j] is either 0 or 1.
    grid[0][0] == grid[m - 1][n - 1] == 0
*/

type Path struct {
	dist  int
	row   int
	col   int
	leftK int
}

// Check the state with row, col, leftK is enough to check if it is visited
func (p Path) toString() string {
	return fmt.Sprintf("%d_%d_%d", p.row, p.col, p.leftK)
}

// Use BFS to find the shortest path.
// Save state not only the distance, but also the obstacle remove count left.
func shortestPath(grid [][]int, k int) int {
	if k >= len(grid)+len(grid[0])-2 {
		return len(grid) + len(grid[0]) - 2
	}

	var curr Path
	checked := map[string]struct{}{}
	q := []Path{Path{0, 0, 0, k}}
	for len(q) > 0 {
		curr, q = q[0], q[1:]
		if curr.row == len(grid)-1 && curr.col == len(grid[0])-1 {
			return curr.dist
		}

		if curr.row-1 >= 0 {
			nextK := curr.leftK - grid[curr.row-1][curr.col]
			nextStep := Path{curr.dist + 1, curr.row - 1, curr.col, nextK}
			if _, ok := checked[nextStep.toString()]; nextK >= 0 && !ok {
				checked[nextStep.toString()] = struct{}{}
				q = append(q, nextStep)
			}
		}

		if curr.row+1 < len(grid) {
			nextK := curr.leftK - grid[curr.row+1][curr.col]
			nextStep := Path{curr.dist + 1, curr.row + 1, curr.col, nextK}
			if _, ok := checked[nextStep.toString()]; nextK >= 0 && !ok {
				checked[nextStep.toString()] = struct{}{}
				q = append(q, nextStep)
			}
		}

		if curr.col-1 >= 0 {
			nextK := curr.leftK - grid[curr.row][curr.col-1]
			nextStep := Path{curr.dist + 1, curr.row, curr.col - 1, nextK}
			if _, ok := checked[nextStep.toString()]; nextK >= 0 && !ok {
				checked[nextStep.toString()] = struct{}{}
				q = append(q, nextStep)
			}
		}

		if curr.col+1 < len(grid[0]) {
			nextK := curr.leftK - grid[curr.row][curr.col+1]
			nextStep := Path{curr.dist + 1, curr.row, curr.col + 1, nextK}
			if _, ok := checked[nextStep.toString()]; nextK >= 0 && !ok {
				checked[nextStep.toString()] = struct{}{}
				q = append(q, nextStep)
			}
		}
	}

	return -1
}
