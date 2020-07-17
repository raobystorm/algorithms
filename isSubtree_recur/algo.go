package issubtree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSubTree(A *TreeNode, B *TreeNode) bool {
	// Only fail when B not included in A
	if A == nil && B != nil {
		return false
	}
	if B == nil {
		return true
	}
	if A.Val != B.Val {
		return false
	}

	return isSubTree(A.Left, B.Left) && isSubTree(A.Right, B.Right)
}

func isSubStructure(A *TreeNode, B *TreeNode) bool {
	if A == nil || B == nil {
		return false
	}

	stk1 := []*TreeNode{A}
	var currNode *TreeNode
	for len(stk1) > 0 {
		currNode, stk1 = stk1[0], stk1[1:]
		if isSubTree(currNode, B) {
			return true
		}
		if currNode.Left != nil {
			stk1 = append(stk1, currNode.Left)
		}
		if currNode.Right != nil {
			stk1 = append(stk1, currNode.Right)
		}
	}
	return false
}
