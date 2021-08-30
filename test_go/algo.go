package testgo

type ListNode struct {
	Val  int
	Next *ListNode
}

func getIntersectionNode(a, b *ListNode) *ListNode {
	headA, headB := a, b
	for a != nil && b != nil {
		if a == b {
			return a
		}
		a = a.Next
		b = b.Next
	}
	if a == nil && b == nil {
		return nil
	}
	var fast, slow, next *ListNode
	if a == nil {
		fast, slow = headB, b
		next = headA
	} else {
		fast, slow = headA, a
		next = headB
	}
	for fast != nil {
		if fast == slow {
			return fast
		}
		if slow.Next == nil {
			slow = next
		} else {
			slow = slow.Next
		}
		fast = fast.Next
	}
	return nil
}
