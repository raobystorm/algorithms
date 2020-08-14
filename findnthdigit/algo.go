package findnthdigit

import (
	"math"
	"strconv"
)

func findNthDigit(n int) int {
	if n <= 9 {
		return n
	}
	prev := 0
	last := 0
	// i is the digits counter
	i := 1
	for {
		// find the correct digit numbers of input n
		// assume digit of n is (i). (prev) is the tail idx of last (i)-1 digit number
		// (last) is the the tail of last (i) digit number
		last = prev + int(math.Pow(10, float64(i-1)))*9*i
		if last >= n {
			break
		}
		prev = last
		i++
	}
	// find the number of n
	num := int(math.Pow(10, float64(i-1))) + (n-prev-1)/i
	// find correct digit of n in (num)
	dig := (n - prev - 1) % i
	s := strconv.Itoa(num)
	return int(s[dig] - '0')
}
