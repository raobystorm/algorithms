package pathSum_recur

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof
func pathSum(root *TreeNode, sum int) [][]int {
	if root == nil {
		return [][]int{}
	}

	// if left value is equal to root.Val
	// return the path, otherwise return []
	if root.Left == nil && root.Right == nil {
		if root.Val == sum {
			return [][]int{{root.Val}}
		} else {
			return [][]int{}
		}
	}

	res := [][]int{}
	if root.Left != nil {
		lRes := pathSum(root.Left, sum-root.Val)
		// all from lRes is valid path, append root.val
		for i := range lRes {
			lRes[i] = append([]int{root.Val}, lRes[i]...)
		}
		res = lRes
	}

	if root.Right != nil {
		rRes := pathSum(root.Right, sum-root.Val)
		for i := range rRes {
			rRes[i] = append([]int{root.Val}, rRes[i]...)
		}
		// merge lRes with rRes
		res = append(res, rRes...)
	}
	return res
}
