package chocolates

func gcd(a int, b int) int {
	if a%b == 0 {
		return b
	}
	return gcd(b, a%b)
}

func Solution(N int, M int) int {
	if N%M == 0 {
		return N / M
	}
	return N / gcd(N, M)
}
