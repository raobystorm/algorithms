package numways

func numWays(n int) int {
	res := make([]int, 101)
	res[0], res[1] = 1, 1
	for i := 2; i < len(res); i++ {
		res[i] = (res[i-1] + res[i-2]) % 1000000007
	}
	return res[n]
}
