package spiralorder

func spiralOrder(m [][]int) []int {
	if len(m) == 0 {
		return []int{}
	}
	// Current border of avalable area
	up, right, down, left := -1, len(m[0]), len(m), -1
	res := make([]int, len(m)*len(m[0]))
	r, c := 0, 0
	goRight, goLeft, goDown, goUp := true, false, false, false
	for curr := 0; curr < len(res); curr++ {
		res[curr] = m[r][c]
		if goRight && c == right-1 {
			if r == down-1 {
				break
			}
			goRight = false
			goDown = true
			up++
		} else if goLeft && c == left+1 {
			if r == up+1 {
				break
			}
			goLeft = false
			goUp = true
			down--
		} else if goDown && r == down-1 {
			if c == left+1 {
				break
			}
			goDown = false
			goLeft = true
			right--
		} else if goUp && r == up+1 {
			if c == right-1 {
				break
			}
			goUp = false
			goRight = true
			left++
		}

		if goRight {
			c++
		} else if goLeft {
			c--
		} else if goUp {
			r--
		} else if goDown {
			r++
		}
	}

	return res
}
