package hascycle

func hasCycle(head *ListNode) bool {
    if head == nil || head.Next == nil {
        return false
    }
    one := head
    two := head.Next
    for one != two {
        one = one.Next
        two = two.Next
        if two == nil {
            return false
        }
        two = two.Next
        if two == nil {
            return false
        }
    }
    return true
}