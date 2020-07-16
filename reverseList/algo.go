package reverselist

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	first := head
	second := head.Next
	if second == nil {
		return first
	}

	third := head.Next.Next
	first.Next = nil
	for third != nil {
		// <- first  second -> third -> ...
		second.Next = first
		first = second
		second = third
		third = third.Next
	}
	second.Next = first
	return second
}
