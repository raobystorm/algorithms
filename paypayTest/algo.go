package paypaytest

import (
	"fmt"
	"strconv"
)

func Test() {
	s := "1111011;1011"
	i := 0
	for i < len(s) {
		if s[i] == ';' {
			break
		}
		i++
	}
	s1, s2 := s[:i], s[i+1:]
	f1, _ := strconv.ParseInt(string(s1), 2, 64)
	f2, _ := strconv.ParseInt(string(s2), 2, 64)
	fmt.Println(strconv.FormatInt(int64(f1+f2), 2))
}
