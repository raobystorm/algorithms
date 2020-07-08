package repeatedstring

import (
	"strings"
)

// RepeatedString test.
func RepeatedString(s string, n int64) int64 {
	cnt := (n / int64(len(s))) * int64(strings.Count(s, "a"))
	l := n % int64(len(s))
	cnt += int64(strings.Count(s[:l], "a"))
	return cnt
}
