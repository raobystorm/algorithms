package lengthoflongestsubstr

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestLengthOfLongest(t *testing.T) {
	assert := assert.New(t)
	assert.Equal(lengthOfLongestSubstring("abba"), 2)
	assert.Equal(lengthOfLongestSubstring("au"), 2)
	assert.Equal(lengthOfLongestSubstring("s"), 1)
	assert.Equal(lengthOfLongestSubstring("abcabcbb"), 3)
	assert.Equal(lengthOfLongestSubstring("bbbbb"), 1)
	assert.Equal(lengthOfLongestSubstring("pwwkew"), 3)
	assert.Equal(lengthOfLongestSubstring("aab"), 2)
	assert.Equal(lengthOfLongestSubstring("tmmzuxt"), 5)
}
