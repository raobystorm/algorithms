package numberofones

func numberOfOnes(num uint32) int {
	cnt := 0
	test := uint32(1)
	for i := 0; i < 32; i++ {
		if test&num > 0 {
			cnt++
		}
		test = test << 1
	}

	return cnt
}
