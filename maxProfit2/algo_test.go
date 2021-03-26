package maxprofit2

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func Test(t *testing.T) {
	assert := assert.New(t)
	assert.Equal(maxProfit([]int{7, 1, 5, 3, 6, 4}), 7)
}
