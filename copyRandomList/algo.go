package copyrandomlist

type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

func copyNext(head *Node) {
	if head == nil {
		return
	}

	newNext := &Node{
		Val:  head.Val,
		Next: head.Next,
	}

	head.Next = newNext
	copyNext(newNext.Next)
}

func copyRandom(head *Node) {
	if head == nil {
		return
	}

	if head.Random != nil {
		head.Next.Random = head.Random.Next
	}

	copyRandom(head.Next.Next)
}

func separateCopied(head *Node, copiedHead *Node) {
	if head.Next == nil && copiedHead.Next == nil {
		return
	}

	next := head.Next
	copiedNext := next.Next
	copiedHead.Next = copiedNext
	next.Next = copiedNext.Next
	separateCopied(next, copiedNext)
}

func copyRandomList(head *Node) *Node {
	if head == nil {
		return nil
	}

	// First copy all nodes and append copied to next pos (1) -> (1') -> (2)
	copyNext(head)
	// Second copy all random links let all copied nodes point to copied ones
	copyRandom(head)

	copiedHead := head.Next
	head.Next = copiedHead.Next
	// Then separate all original nodes from copied nodes and break next links
	separateCopied(head, copiedHead)
	return copiedHead
}
