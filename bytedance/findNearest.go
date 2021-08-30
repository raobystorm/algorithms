package bytedance

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func abs(i int) int {
	if i < 0 {
		return -1 * i
	}
	return i
}

func FindNearest(root *TreeNode, t int) *TreeNode {
	if root == nil {
		return nil
	}
	if root.Val < t {
		right := FindNearest(root.Right, t)
		if right != nil && abs(right.Val-t) < abs(root.Val-t) {
			return right
		}
		return root
	}
	left := FindNearest(root.Left, t)
	if left != nil && abs(left.Val-t) < abs(root.Val-t) {
		return left
	}
	return root
}
