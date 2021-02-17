package firstmissingpositive

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestFirstMissingPositive(t *testing.T) {
	assert := assert.New(t)
	assert.Equal(3, firstMissingPositive([]int{0, 1, 2}))
}