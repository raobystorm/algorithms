package lengthoflis

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestLengthOfLongest(t *testing.T) {
	assert := assert.New(t)
	assert.Equal(4, lengthOfLIS([]int{10, 9, 2, 5, 3, 7, 101, 18}))
}
