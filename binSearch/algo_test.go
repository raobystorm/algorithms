package binsearch

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestBinSearch(t *testing.T) {
	assert := assert.New(t)
	n := []int{0, 1, 2, 2, 2, 3, 4, 4, 5, 7, 9}
	// For bSearch1
	assert.Equal(5, bSearch1(n, 3, 0, len(n)-1))
	assert.Equal(0, bSearch1(n, 0, 0, len(n)-1))
	assert.Equal(8, bSearch1(n, 5, 0, len(n)-1))
	// bSearch2
	assert.Equal(5, bSearch2(n, 3))
	assert.Equal(0, bSearch2(n, 0))
	assert.Equal(8, bSearch2(n, 5))

	// bSearch3
	// For multiple values find first index
	assert.Equal(2, bSearch3(n, 2))
	assert.Equal(6, bSearch3(n, 4))
	// For unique value find exact index
	assert.Equal(5, bSearch3(n, 3))
	// For edge find index
	assert.Equal(0, bSearch3(n, 0))
	assert.Equal(0, bSearch3(n, -1))
	assert.Equal(10, bSearch3(n, 11))
	// For non-existing target find index of largest num that less than target
	assert.Equal(8, bSearch3(n, 6))

	// bSearch4
	// For multiple values find first index
	assert.Equal(2, bSearch4(n, 2))
	assert.Equal(6, bSearch4(n, 4))
	// For unique value find exact index
	assert.Equal(5, bSearch4(n, 3))
	// For edge find index
	assert.Equal(0, bSearch4(n, 0))
	assert.Equal(0, bSearch4(n, -1))
	assert.Equal(11, bSearch4(n, 11))
	// For non-existing target find index of largest num that less than target
	assert.Equal(9, bSearch4(n, 6))
}
