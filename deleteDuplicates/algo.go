package deleteduplicates

func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    curr := head
    next := curr.Next
    for next != nil {
        for next != nil && curr.Val == next.Val {
            curr.Next = next.Next
            next = next.Next
        }
        curr = next
        if next != nil {
            next = next.Next
        }
    }
    return head
}