package translateNum

import "strconv"

func translateNum(num int) int {
	str := strconv.Itoa(num)
	res, prev := 1, 1
	for i := range str {
		if i == 0 {
			continue
		}
		if (str[i-1] == '2' && str[i] <= '5') || (str[i-1] == '1') {
			prev, res = res, res+prev
		} else {
			prev = res
		}
	}
	return res
}
