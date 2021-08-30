package pathsumii

// 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

// 叶子节点 是指没有子节点的节点。

// 示例 1：
// 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// 输出：[[5,4,11,2],[5,8,4,5]]

// 示例 2：
// 输入：root = [1,2,3], targetSum = 5
// 输出：[]

// 示例 3：
// 输入：root = [1,2], targetSum = 0
// 输出：[]
//
// 提示：
// 树中节点总数在范围 [0, 5000] 内
// -1000 <= Node.val <= 1000
// -1000 <= targetSum <= 1000

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 使用dfs+回溯法。用一个[]int来保存当前的路径，往下或者回退的时候更新路径数组
func dfs(root *TreeNode, t int, path *[]int, res *[][]int) {
	if root.Left == nil && root.Right == nil {
		if t-root.Val == 0 {
			newRes := make([]int, len(*path)+1)
			copy(newRes, *path)
			newRes[len(newRes)-1] = root.Val
			*res = append(*res, newRes)
		}
		return
	}

	if root.Left != nil {
		*path = append(*path, root.Val)
		dfs(root.Left, t-root.Val, path, res)
		*path = (*path)[:len(*path)-1]
	}

	if root.Right != nil {
		*path = append(*path, root.Val)
		dfs(root.Right, t-root.Val, path, res)
		*path = (*path)[:len(*path)-1]
	}
}

func pathSum(root *TreeNode, t int) [][]int {
	if root == nil {
		return [][]int{}
	}

	res := [][]int{}
	dfs(root, t, &[]int{}, &res)
	return res
}
