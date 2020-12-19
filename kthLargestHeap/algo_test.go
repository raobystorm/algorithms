package kthlargestheap

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestKthLargest(t *testing.T) {
	assert := assert.New(t)
	k := Constructor(3, []int{4,5,8,2})
	assert.Equal(k.Add(3), 4)
	assert.Equal(k.Add(5), 5)
	assert.Equal(k.Add(10), 5)
	assert.Equal(k.Add(9), 8)
	assert.Equal(k.Add(4), 8)
}