package isvalidbst

type ExtNode struct {
	maxVal int
	minVal int
	isOk   bool
	level  int
}

func recur(root *TreeNode) *ExtNode {
	if root == nil {
		return nil
	}

	left := recur(root.Left)
	right := recur(root.Right)

	level := 0

	if left == nil && right == nil {
		return &ExtNode{root.Val, root.Val, true, 1}
	}

	if left != nil && !left.isOk {
		goto err
	}

	if right != nil && !right.isOk {
		goto err
	}
	// one side is nil
	if left == nil {
		if right.minVal <= root.Val {
			goto err
		}
		return &ExtNode{right.maxVal, root.Val, true, 2}
	}
	if right == nil {
		if left.maxVal >= root.Val {
			goto err
		}
		return &ExtNode{root.Val, left.minVal, true, 2}
	}
	// both is not nil and ok
	if left.maxVal >= root.Val || right.minVal <= root.Val {
		goto err
	}

	if left.level > right.level {
		level = left.level + 1
	} else {
		level = right.level + 1
	}

	return &ExtNode{right.maxVal, left.minVal, true, level}

err:
	return &ExtNode{-1, -1, false, -1}
}

func isValidBST(root *TreeNode) bool {
	return recur(root).isOk
}
