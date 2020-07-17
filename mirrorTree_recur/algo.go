package mirrortree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func recur(n *TreeNode) {
	if n != nil {
		n.Left, n.Right = n.Right, n.Left
		recur(n.Left)
		recur(n.Right)
	}
}

func mirrorTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

	recur(root)
	return root
}
