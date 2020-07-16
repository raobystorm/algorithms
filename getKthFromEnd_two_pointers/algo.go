package getkthfromend

type ListNode struct {
	Val  int
	Next *ListNode
}

func GetKthFromEnd(head *ListNode, k int) *ListNode {
	first := head
	second := head
	for i := 0; i < k; i++ {
		if first != nil {
			first = first.Next
		}
	}

	for first != nil {
		first = first.Next
		second = second.Next
	}

	return second
}
