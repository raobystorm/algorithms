package addtwonumbers

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    if l1 == nil {
        return l2
    }
    if l2 == nil {
        return l1
    }
    var curr, head *ListNode
    res := 0
    carry := 0
    for {
        if l1 != nil && l2 != nil {
            res = l1.Val + l2.Val + carry
        } else if l2 != nil {
            res = l2.Val + carry
        } else if l1 != nil {
            res = l1.Val + carry
        } else {
            res = carry
        }
        carry = res / 10
        res = res % 10
        if curr == nil {
            head = &ListNode{
                Val: res,
            }
            curr = head
        } else {
            curr.Next = &ListNode{
                Val: res,
            }
            curr = curr.Next
        }
        if l1 != nil {
            l1 = l1.Next
        }
        if l2 != nil {
            l2 = l2.Next
        }
        if l1 == nil && l2 == nil && carry == 0 {
            break
        }
    }
    return head
}