package issymmetric

// 给定一个二叉树，检查它是否是镜像对称的。

// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//

// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

//     1
//    / \
//   2   2
//    \   \
//    3    3

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 使用队列。层序遍历
func isSymmetricQueue(root *TreeNode) bool {
	if root == nil {
		return false
	}
	if root.Left == nil && root.Right == nil {
		return true
	}

	curr := []*TreeNode{root}
	for len(curr) > 0 {
		for i := 0; i < len(curr)/2; i++ {
			if curr[i] == nil && curr[len(curr)-1-i] == nil {
				continue
			}
			if curr[i] == nil || curr[len(curr)-1-i] == nil {
				return false
			}
			if curr[i].Val != curr[len(curr)-1-i].Val {
				return false
			}
		}
		next := []*TreeNode{}
		for i := range curr {
			if curr[i] == nil {
				continue
			}
			next = append(next, curr[i].Left, curr[i].Right)
		}
		curr = next
	}
	return true
}

// 使用递归。这个递归在两个节点上递归
func isSymmetricRecur(n1 *TreeNode, n2 *TreeNode) bool {
	if n1 == nil && n2 == nil {
		return true
	}

	if n1 == nil || n2 == nil {
		return false
	}

	if n1.Val != n2.Val {
		return false
	}

	return isSymmetricRecur(n1.Left, n2.Right) && isSymmetricRecur(n1.Right, n2.Left)
}

func isSymmetric(root *TreeNode) bool {
	return isSymmetricRecur(root, root)
}
