package reorderlist

// 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
// 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

// 示例 1:

// 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
// 示例 2:

// 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverse(head *ListNode) *ListNode {
	if head.Next == nil {
		return head
	}
	prev := head
	curr := head.Next
	next := curr.Next
	prev.Next = nil
	for next != nil {
		curr.Next = prev
		prev = curr
		curr = next
		next = next.Next
	}
	curr.Next = prev
	return curr
}

// 先将链表一半进行反转，然后用双指针交叉连接
func reorderList(head *ListNode) {
	if head == nil || head.Next == nil || head.Next.Next == nil {
		return
	}
	cnt := 1
	curr := head
	for curr.Next != nil {
		curr = curr.Next
		cnt++
	}
	half := cnt / 2
	middle := head
	for i := 0; i < half; i++ {
		middle = middle.Next
	}
	tail := reverse(middle)
	curr = head
	nextHead := curr.Next
	nextTail := tail.Next
	curr.Next = tail
	tail.Next = nextHead
	for nextHead != nextTail && nextHead != nil && nextTail != nil {
		curr = nextHead
		nextHead = nextHead.Next
		tail = nextTail
		nextTail = nextTail.Next
		curr.Next = tail
		if nextHead != tail {
			tail.Next = nextHead
		}
	}
}
