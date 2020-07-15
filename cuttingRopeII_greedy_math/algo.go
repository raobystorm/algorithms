package cuttingropeii

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

	// The answer is try to maximize segments of length 3
	threes := n / 3
	if n-threes*3 == 1 {
		threes--
	}

	// Then look for the last segments, if remain is len 1
	// then reduce one len 3 seg and use both as a 2x2 segs, because 2x2 > 1x3
	twos := (n - threes*3) / 2
	res := 1
	for i := 0; i < threes; i++ {
		res = (res * 3) % 1000000007
	}
	for i := 0; i < twos; i++ {
		res = (res * 2) % 1000000007
	}
	return res
}
