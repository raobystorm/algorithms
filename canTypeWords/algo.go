package cantypewords

func canBeTypedWords(text string, bl string) int {
	res := 1
	cMap := map[byte]struct{}{}
	for i := range bl {
		cMap[bl[i]] = struct{}{}
	}
	contains := false
	for i := range text {
		if text[i] == ' ' {
			contains = false
			res++
			continue
		}
		if contains {
			continue
		}
		if _, ok := cMap[text[i]]; ok {
			res--
			contains = true
		}
	}
	return res
}
