package buildtree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}

	root := preorder[0]
	lIdx := 0
	for lIdx < len(preorder) {
		if inorder[lIdx] == root {
			break
		}
		lIdx++
	}

	var lNode, rNode *TreeNode
	if lIdx > 0 {
		lNode = buildTree(preorder[1:lIdx+1], inorder[:lIdx])
	}
	if lIdx+1 < len(preorder) {
		rNode = buildTree(preorder[lIdx+1:], inorder[lIdx+1:])
	}

	return &TreeNode{root, lNode, rNode}
}
