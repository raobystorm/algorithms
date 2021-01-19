package ladderlength

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestLadderLength(t *testing.T) {
	assert := assert.New(t)
	assert.Equal(5, ladderLength("hit", "cog", []string{"hot","dot","dog","lot","log","cog"}))
}
