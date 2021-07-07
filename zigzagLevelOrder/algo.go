package zigzaglevelorder

// 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

// 例如：
// 给定二叉树 [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回锯齿形层序遍历如下：

// [
//   [3],
//   [20,9],
//   [15,7]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func zigzagLevelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	res := [][]int{}
	queue := []*TreeNode{root}
	lvl := 1
	for len(queue) != 0 {
		next := []*TreeNode{}
		currRes := []int{}
		for i := range queue {
			currRes = append(currRes, queue[i].Val)
			if queue[i].Left != nil {
				next = append(next, queue[i].Left)
			}
			if queue[i].Right != nil {
				next = append(next, queue[i].Right)
			}
		}
		if lvl%2 == 0 {
			i, j := 0, len(currRes)-1
			for i < j {
				currRes[i], currRes[j] = currRes[j], currRes[i]
				i++
				j--
			}
		}
		res = append(res, currRes)
		queue = next
		lvl++
	}
	return res
}
