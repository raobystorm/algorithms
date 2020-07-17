package issymmetric

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func treeMirror(n1 *TreeNode, n2 *TreeNode) bool {
	if n1 == nil && n2 == nil {
		return true
	}

	if n1 == nil || n2 == nil {
		return false
	}

	if n1.Val != n2.Val {
		return false
	}

	return treeMirror(n1.Left, n2.Right) && treeMirror(n1.Right, n2.Left)
}

func isSymmetric(root *TreeNode) bool {
	return treeMirror(root, root)
}
