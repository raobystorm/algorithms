package detectcycle

func detectCycle(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return nil
    }
    one := head
    two := head
    for {
        one = one.Next
        if one == nil {
            return nil
        }
        if two == nil || two.Next == nil {
            return nil
        }
        two = two.Next.Next
        if one == two {
            break
        }
    }
    one = head
    for one != two {
        one = one.Next
        two = two.Next
    }
    return one
}