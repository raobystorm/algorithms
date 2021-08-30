package detectcycle

// 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

// 说明：不允许修改给定的链表。

// 进阶：
// 你是否可以使用 O(1) 空间解决此题？

// 示例 1：
// 输入：head = [3,2,0,-4], pos = 1
// 输出：返回索引为 1 的链表节点
// 解释：链表中有一个环，其尾部连接到第二个节点。

// 示例 2：
// 输入：head = [1,2], pos = 0
// 输出：返回索引为 0 的链表节点
// 解释：链表中有一个环，其尾部连接到第一个节点。

// 示例 3：
// 输入：head = [1], pos = -1
// 输出：返回 null
// 解释：链表中没有环。
//

type ListNode struct {
	Val  int
	Next *ListNode
}

// 思路：双指针，一个快一个慢。两者相遇的时候将快指针重新放到头部，然后减慢速度。
// 再一次相遇的时候即为环的第一个节点。
// 证明：慢指针前进速度为 v，则快指针为 2v。
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
