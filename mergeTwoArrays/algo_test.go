package mergetwoarrays

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestSolution(t *testing.T) {
	assert := assert.New(t)
	res := merge([]int{1, 2, 3, 0, 0, 0}, 3, []int{2, 5, 6}, 3)
	assert.Equal(res, []int{1, 2, 2, 3, 5, 6})
}
