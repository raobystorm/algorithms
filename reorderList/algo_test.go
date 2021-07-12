package reorderlist

import "testing"

func TestSolution(t *testing.T) {
	head := &ListNode{
		Val: 1,
		Next: &ListNode{
			Val: 2,
		},
	}
	reorderList(head)
}
