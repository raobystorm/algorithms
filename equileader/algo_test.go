package equileader

import "testing"

func TestSolution(t *testing.T) {
	if Solution([]int{4, 3, 4, 4, 4, 2}) != 2 {
		panic("")
	}
}
