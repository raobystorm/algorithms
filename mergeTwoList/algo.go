package mergetwolists

// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

// 示例 1：

// 输入：l1 = [1,2,4], l2 = [1,3,4]
// 输出：[1,1,2,3,4,4]

// 示例 2：

// 输入：l1 = [], l2 = []
// 输出：[]

// 示例 3：

// 输入：l1 = [], l2 = [0]
// 输出：[0]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

type ListNode struct {
	Val  int
	Next *ListNode
}

func min(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}
	if l2 == nil {
		return l1
	}
	if l1.Val < l2.Val {
		return l1
	}
	return l2
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	res := min(l1, l2)
	curr := res
	for l1 != nil || l2 != nil {
		if curr == l1 {
			l1 = l1.Next
		} else {
			l2 = l2.Next
		}
		curr.Next = min(l1, l2)
		curr = curr.Next
	}
	return res
}
