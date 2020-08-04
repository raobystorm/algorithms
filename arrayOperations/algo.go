package arrayoperations

/*
	[0, 0, 0, 0, 0]

	[1, 2, 1]
	[2, 4, 2]
	[1, 4, 3]

	[0, 1, 1, 0, 0]
	[0, 1, 3, 2, 2]
	[0, 4, 6, 5, 5]
->

	[1: 4]
	[3: -1]
	[2: 2]

*/
func ArrayOps(ops [][]int, arr []int) []int {
	merged := map[int]int{}
	for i := range ops {
		if _, ok := merged[ops[i][0]]; ok {
			merged[ops[i][0]] += ops[i][2]
		} else {
			merged[ops[i][0]] = ops[i][2]
		}
		if ops[i][1]+1 < len(arr) {
			if _, ok := merged[ops[i][1]+1]; ok {
				merged[ops[i][1]+1] -= ops[i][2]
			} else {
				merged[ops[i][1]+1] = 0 - ops[i][2]
			}
		}
	}

	res := make([]int, len(arr))
	prev := 0
	for i := range arr {
		if _, ok := merged[i]; ok {
			prev += merged[i]
		}
		res[i] = prev
	}

	return res
}
