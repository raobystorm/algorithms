package mypow

func myPosPow(x float64, n int) float64 {
	if n%2 == 1 {
		res := myPow(x, (n-1)>>1)
		return res * res * x
	}
	res := myPow(x, n/2)
	return res * res
}

// a^n = a^(n/2) * a^(n/2) if n % 2 == 0
//       a^((n-1)/2) * a^((n-1)/2) * a if n % 2 == 1
func myPow(x float64, n int) float64 {
	if n == 0 {
		return float64(1.0)
	}
	if n < 0 {
		return float64(1.0) / myPosPow(x, -1*n)
	}
	return myPosPow(x, n)
}
