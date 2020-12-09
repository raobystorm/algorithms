package levelorder2

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	curr := []*TreeNode{root}
	next := []*TreeNode{}
	res := [][]int{}
	var currNode *TreeNode
	for len(curr) > 0 {
		currRes := []int{}
		for len(curr) > 0 {
			currNode, curr = curr[0], curr[1:]
			if currNode.Left != nil {
				next = append(next, currNode.Left)
			}
			if currNode.Right != nil {
				next = append(next, currNode.Right)
			}
			currRes = append(currRes, currNode.Val)
		}
		curr = next
		next = []*TreeNode{}
		res = append(res, currRes)
	}
	return res
}
