package rotatestring

func checkStr(a string, i int, b string) bool {
	aa := a[i:] + a[:i]
	return aa == b
}

func rotateString(A string, B string) bool {
	if A == "" && B == "" {
		return true
	}
	if len(A) != len(B) {
		return false
	}

	for i := range B {
		if B[i] != A[0] {
			continue
		}
		if checkStr(B, i, A) {
			return true
		}
	}
	return false
}
