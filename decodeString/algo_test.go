package decodestring

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestDecodeString(t *testing.T) {
	assert := assert.New(t)
	assert.Equal(decodeString("3[a]2[bc]"), "aaabcbc")
	assert.Equal(decodeString("3[a2[c]]"), "accaccacc")
	assert.Equal(decodeString("2[abc]3[cd]ef"), "abcabccdcdcdef")
	assert.Equal(decodeString("abc3[cd]xyz"), "abccdcdcdxyz")	
}