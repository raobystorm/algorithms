package numislands

func dfs(m [][]bool, i int, j int, grid [][]byte) {
    if m[i][j] || grid[i][j] == '0' {
        return
    }
    
    m[i][j] = true
    if i > 0 {
        dfs(m, i-1, j, grid)
    }
    if i < len(grid) - 1 {
        dfs(m, i+1, j, grid)
    }
    if j > 0 {
        dfs(m, i, j-1, grid)
    }
    if j < len(grid[0]) - 1 {
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
            q = append(q, []int{curr[0]-1, curr[1]})
        }
        if curr[0] < len(grid)-1 && grid[curr[0]+1][curr[1]] == '1' {
            q = append(q, []int{curr[0]+1, curr[1]})
        }
        if curr[1] > 0 && grid[curr[0]][curr[1]-1] == '1' {
            q = append(q, []int{curr[0], curr[1]-1})
        }
        if curr[1] < len(grid[0])-1 && grid[curr[0]][curr[1]+1] == '1' {
            q = append(q, []int{curr[0], curr[1]+1})
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