package jumponclouds

// JumpingOnClouds test.
func JumpingOnClouds(c []int32) int32 {
	var a [3]int32 = [3]int32{1, 0, 0}
	for i := 2; i < len(c); i++ {
		if c[i] == 1 {
			a[0], a[1], a[2] = 101, a[0], a[1]
		} else {
			if a[0] > a[1] {
				a[0], a[1], a[2] = a[1]+1, a[0], a[1]
			} else {
				a[0], a[1], a[2] = a[0]+1, a[0], a[1]
			}
		}
	}
	return a[0]
}
