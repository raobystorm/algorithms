package movingcount

type step struct {
	r int
	c int
}

func MovingCount(m int, n int, k int) int {
	canGo := [100][100]bool{}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if i%10+i/10+j%10+j/10 <= k {
				canGo[i][j] = true
			}
		}
	}

	// bfs
	queue := []*step{{r: 0, c: 0}}
	canGo[0][0] = false
	cnt := 1
	for len(queue) > 0 {
		curr := queue[0]
		queue = queue[1:]
		if curr.r > 0 && canGo[curr.r-1][curr.c] {
			cnt++
			queue = append(queue, &step{r: curr.r - 1, c: curr.c})
			canGo[curr.r-1][curr.c] = false
		}
		if curr.c > 0 && canGo[curr.r][curr.c-1] {
			cnt++
			queue = append(queue, &step{r: curr.r, c: curr.c - 1})
			canGo[curr.r][curr.c-1] = false
		}
		if curr.r+1 < m && canGo[curr.r+1][curr.c] {
			cnt++
			queue = append(queue, &step{r: curr.r + 1, c: curr.c})
			canGo[curr.r+1][curr.c] = false
		}
		if curr.c+1 < n && canGo[curr.r][curr.c+1] {
			cnt++
			queue = append(queue, &step{r: curr.r, c: curr.c + 1})
			canGo[curr.r][curr.c+1] = false
		}
	}

	return cnt
}
