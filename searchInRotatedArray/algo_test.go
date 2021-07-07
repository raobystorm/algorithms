package searchinrotatedarray

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestSolution(t *testing.T) {
	assert := assert.New(t)
	assert.Equal(0, search([]int{3, 5, 1}, 3))
}
