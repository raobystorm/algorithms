package canreach

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	fmt.Println(canReach([]int{4, 2, 3, 0, 3, 1, 2}, 0))
}
