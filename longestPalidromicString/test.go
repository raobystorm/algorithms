package longestPalidromicString

func LongestPalindrome(s string) string {
	var rightSubStr string
	var longSubStr string
	for i, c := range s {
		if i-len(rightSubStr)-1 >= 0 && s[i] == s[i-len(rightSubStr)-1] {
			if len(rightSubStr)+2 < len(s) {
				rightSubStr = s[i-len(rightSubStr)-1 : i+1]
			}
		} else if len(rightSubStr) == 1 && s[i] == rightSubStr[0] {
			rightSubStr = s[i-1 : i+1]
		} else {
			rightSubStr = string(c)
		}
		if len(rightSubStr) >= len(longSubStr) {
			longSubStr = rightSubStr
		}
	}

	return longSubStr
}
