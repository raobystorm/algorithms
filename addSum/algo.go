package addsum

// 给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
// 每条从根节点到叶节点的路径都代表一个数字：

// 例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
// 计算从根节点到叶节点生成的 所有数字之和 。
// 叶节点 是指没有子节点的节点。

// 示例 1：
// 输入：root = [1,2,3]
// 输出：25
// 解释：
// 从根到叶子节点路径 1->2 代表数字 12
// 从根到叶子节点路径 1->3 代表数字 13
// 因此，数字总和 = 12 + 13 = 25

// 示例 2：
// 输入：root = [4,9,0,5,1]
// 输出：1026
// 解释：
// 从根到叶子节点路径 4->9->5 代表数字 495
// 从根到叶子节点路径 4->9->1 代表数字 491
// 从根到叶子节点路径 4->0 代表数字 40
// 因此，数字总和 = 495 + 491 + 40 = 1026
//

// 提示：

// 树中节点的数目在范围 [1, 1000] 内
// 0 <= Node.val <= 9
// 树的深度不超过 10

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 使用数组保存中间结果比较方便，或者是string
// 如果每一次递归都用int，则要特殊处理root.Val为0的情况。也要考虑子树当中可能右边有层数少一层的情况。
// 如果使用数组或者string就不需要特殊处理
func recur(root *TreeNode) [][]int {
	left, right := [][]int{}, [][]int{}
	if root.Left != nil {
		left = recur(root.Left)
	}
	if root.Right != nil {
		right = recur(root.Right)
	}

	res := [][]int{}
	for i := range left {
		res = append(res, append([]int{root.Val}, left[i]...))
	}
	for i := range right {
		res = append(res, append([]int{root.Val}, right[i]...))
	}
	if len(res) == 0 {
		return [][]int{{root.Val}}
	}
	return res
}

func sumNumbers(root *TreeNode) int {
	arr := recur(root)
	res := 0
	for i := range arr {
		dig := 1
		j := len(arr[i]) - 1
		for j >= 0 {
			res += dig * arr[i][j]
			dig *= 10
			j--
		}
	}
	return res
}
