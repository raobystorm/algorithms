package verifypostorder

// check if all of subtree is smaller / larger than root
func checkSub(sub []int, root int, larger bool) bool {
	for _, v := range sub {
		if (larger && v < root) || (!larger && v > root) {
			return false
		}
	}
	return true
}

// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
func verifyPostorder(po []int) bool {
	if len(po) < 2 {
		// LeetCode said [] is true...
		return true
	}

	// Divide left subtree & right subtree according left.all < root < right.all
	root := po[len(po)-1]
	idx := len(po) - 2
	for idx >= 0 && po[idx] > root {
		idx--
	}
	if idx > -1 {
		left := po[:idx+1]
		// check if left subtree is validated and this root is validated
		if !(checkSub(left, root, false) && verifyPostorder(left)) {
			return false
		}
	}
	if idx+1 < len(po)-1 {
		right := po[idx+1 : len(po)-1]
		if !(checkSub(right, root, true) && verifyPostorder(right)) {
			return false
		}
	}
	return true
}
