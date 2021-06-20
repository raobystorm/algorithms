package numsplits

func numSplits(s string) int {
	if len(s) == 0 {
		return 0
	}
	cnt1 := map[byte]int{}
	cnt2 := map[byte]int{}
	res := 0
	for i := range s {
		if _, ok := cnt2[s[i]]; !ok {
			cnt2[s[i]] = 1
		} else {
			cnt2[s[i]]++
		}
	}
	for i := range s {
		cnt2[s[i]]--
		if cnt2[s[i]] == 0 {
			delete(cnt2, s[i])
		}
		if _, ok := cnt1[s[i]]; !ok {
			cnt1[s[i]] = 1
		} else {
			cnt1[s[i]]++
		}
		if len(cnt1) == len(cnt2) {
			res++
		}
	}
	return res
}
