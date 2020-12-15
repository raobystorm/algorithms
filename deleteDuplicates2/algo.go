package deleteduplicates

type ListNode struct {
	Val int
	Next *ListNode
}

func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    var prev *ListNode
    curr := head
    for curr != nil {
        // check if curr dup
        isDup := false
        dupVal := curr.Val
        next := curr.Next
        // move next to not dup from curr
        for next != nil && next.Val == dupVal {
            isDup = true
            next = next.Next
        }
        if next != nil {
            // not tail of list
            if isDup {
                if prev == nil {
                    // prev: nil, curr: 1, 1, next: 2
                    head = next
                    curr = head
                } else {
                    // prev: 1, curr: 2, 2, 2, next: 3
                    prev.Next = next
                    curr = next
                }
            } else {
                // prev: 1 | nil, curr: 2, next: 3
                prev = curr
                curr = curr.Next
            }         
        } else {
            // next == nil, curr (and dups) is the tail of list
            if isDup {
                if prev == nil {
                    // prev: nil, curr: 1, 1, 1, next: nil
                    return nil
                }
                // prev: 1, curr: 2, 2, 2, next: nil
                prev.Next = nil
                return head
            } else {
                // because no dups and is tail of list, just return
                return head
            }
        }
    }
    
    return head
}