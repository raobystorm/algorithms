package rightsideview

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

// 示例:

// 输入: [1,2,3,null,5,null,4]
// 输出: [1, 3, 4]
// 解释:

//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

func rightSideView(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}

	left := rightSideView(root.Left)
	right := rightSideView(root.Right)

	if len(left) > len(right) {
		copy(left, right)
		right = left
	}
	return append([]int{root.Val}, right...)
}
