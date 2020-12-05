package levelorder

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrder(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}

	res := []int{}
	curr := []*TreeNode{root}
	var node *TreeNode
	for len(curr) > 0 {
		node, curr = curr[0], curr[1:]
		res = append(res, node.Val)
		if node.Left != nil {
			curr = append(curr, node.Left)
		}
		if node.Right != nil {
			curr = append(curr, node.Right)
		}
	}
	return res
}
