package deleteduplicates

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func makeList(n []int) *ListNode {
	head := &ListNode{
		Val: n[0],
	}
	curr := head
	for i := range n {
		if i == 0 {
			continue
		}
		curr.Next = &ListNode{
			Val: n[i],
		}
		curr = curr.Next
	}
	return head
}

func TestDeleteDuplicats(t *testing.T) {
	assert := assert.New(t)
	head := makeList([]int{2,2, 4,4})
	assert.Equal(deleteDuplicates(head), nil.(*ListNode))
}