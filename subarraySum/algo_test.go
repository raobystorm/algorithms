package subarraysum

import (
	"fmt"
	"strconv"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestSubarraySum(t *testing.T) {
	assert := assert.New(t)
	res := subarraySum([]int{1,2,3,4,5,6,7,1,23,21,3,1,2,1,1,1,1,1,12,2,3,2,3,2,2}, 6)
	fmt.Printf(strconv.Itoa(res))
	assert.Equal(res, 5)
}