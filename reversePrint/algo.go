package reverseprint

type ListNode struct {
	Val  int
	Next *ListNode
}

func reversePrint(head *ListNode) []int {
	if head == nil {
		return []int{}
	}

	res := make([]int, 10001)
	cnt := 0
	for head != nil {
		cnt++
		res[cnt-1] = head.Val
		head = head.Next
	}

	res = res[:cnt]
	for i := 0; i < (len(res)+1)/2; i++ {
		res[i], res[len(res)-i-1] = res[len(res)-i-1], res[i]
	}

	return res
}
