package haspathsum

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func hasPathSum(root *TreeNode, t int) bool {
	if root == nil {
		return false
	}
	if root.Left == nil && root.Right == nil {
		return root.Val == t
	}
	return hasPathSum(root.Left, t-root.Val) || hasPathSum(root.Right, t-root.Val)
}
