package stonewall

import "testing"

func TestSolution(t *testing.T) {
	if Solution([]int{8, 8, 5, 7, 9, 8, 7, 4, 8}) != 7 {
		panic("")
	}
}
