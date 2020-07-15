package cuttingrope

func cuttingRope(n int) int {
	if n < 2 {
		return 0
	}
	if n == 2 {
		return 1
	}
	if n == 3 {
		return 2
	}

	max := [59]int{}
	// Here max[i] != cuttingRope(i), for example, when comes to 2
	// cuttingRope(2) should be 1 but max[2] should be 2.
	// Because for all i > 2, we could cut rope at i == 2
	// At i == 2 len(0..2) = 2 not 1. The same with i == 3
	max[0], max[1], max[2], max[3] = 0, 1, 2, 3
	for i := 4; i <= n; i++ {
		currMax := 0
		for j := 1; j <= (i+1)/2; j++ {
			if max[j]*max[i-j] > currMax {
				currMax = max[j] * max[i-j]
			}
		}
		max[i] = currMax
	}
	return max[n]
}
