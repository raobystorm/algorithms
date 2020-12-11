package lengthoflongestsubstr

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func lengthOfLongestSubstring(s string) int {
	if len(s) <= 1 {
		return len(s)
	}
	// key: char, value: index of char
	chars := make(map[byte]struct{})
	i, j := 0, 0
	res := 1
	for j < len(s) {
		c := s[j]
		_, ok := chars[c]
		for ok {
			delete(chars, s[i])
			i++
			_, ok = chars[c]
		}
		chars[c] = struct{}{}
		res = max(res, j - i + 1)
		j++
	}
	return res
}
