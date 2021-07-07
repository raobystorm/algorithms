package getintersectionnode

import "testing"

func TestSolution(t *testing.T) {
	join := ListNode{
		Val: 8,
		Next: &ListNode{
			Val: 4,
			Next: &ListNode{
				Val:  5,
				Next: nil,
			},
		},
	}
	headA := &ListNode{
		Val: 4,
		Next: &ListNode{
			Val:  1,
			Next: &join,
		},
	}
	headB := &ListNode{
		Val: 5,
		Next: &ListNode{
			Val: 0,
			Next: &ListNode{
				Val:  1,
				Next: &join,
			},
		},
	}
	getIntersectionNode(headA, headB)
}
