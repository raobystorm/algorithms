package getintersectionnode

type ListNode struct {
	Val  int
	Next *ListNode
}

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	if headA == nil || headB == nil {
		return nil
	}
	A, B := headA, headB
	for A != nil && B != nil {
		A = A.Next
		B = B.Next
	}
	if A == nil {
		A = headB
	}
	if B == nil {
		B = headA
	}
	for A != nil || B != nil {
		if A == nil {
			A = headB
		}
		if B == nil {
			B = headA
		}
		if A == B {
			return A
		}
		A = A.Next
		B = B.Next
	}
	return nil
}
