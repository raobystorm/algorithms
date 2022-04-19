package findleaves

/*

Given the root of a binary tree, collect a tree's nodes as if you were doing this:

    Collect all the leaf nodes.
    Remove all the leaf nodes.
    Repeat until the tree is empty.

Example 1:

Input: root = [1,2,3,4,5]
Output: [[4,5,3],[2],[1]]
Explanation:
[[3,5,4],[2],[1]] and [[3,4,5],[2],[1]] are also considered correct answers since per each level it does not matter the order on which elements are returned.

Example 2:

Input: root = [1]
Output: [[1]]


Constraints:

    The number of nodes in the tree is in the range [1, 100].
    -100 <= Node.val <= 100

*/

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func upsert(val int, d int, depths *map[int][]int) {
	if _, ok := (*depths)[d]; ok {
		(*depths)[d] = append((*depths)[d], val)
		return
	}
	(*depths)[d] = []int{val}
}

// Use dfs to calculate the depth of each node, and save to a map
func calcDepth(n *TreeNode, depths *map[int][]int) int {
	if n == nil {
		return -1
	}
	if n.Left == nil && n.Right == nil {
		upsert(n.Val, 0, depths)
		return 0
	}

	currDepth := max(calcDepth(n.Left, depths), calcDepth(n.Right, depths)) + 1
	upsert(n.Val, currDepth, depths)
	return currDepth
}

func findLeaves(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{{}}
	}

	depths := map[int][]int{}
	calcDepth(root, &depths)

	res := [][]int{}
	for i := 0; i < len(depths); i++ {
		res = append(res, depths[i])
	}
	return res
}
