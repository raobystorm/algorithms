package zigzaglevelorder

func recur(root *TreeNode, firstLevel bool) [][]int {
	if root == nil {
		return [][]int{}
	}

	if root.Left == nil && root.Right == nil {
		return [][]int{[]int{root.Val}}
	}

	ltree := recur(root.Left, false)
	rtree := recur(root.Right, false)

	res := [][]int{[]int{root.Val}}
	for i := 0; i < len(ltree) || i < len(rtree); i++ {
		if i < len(ltree) {
			if i < len(rtree) {
				res = append(res, append(ltree[i], rtree[i]...))
			} else {
				res = append(res, ltree[i])
			}
		} else {
			res = append(res, rtree[i])
		}
	}

	if firstLevel {
		for i := 0; i < len(res); i++ {
			if i%2 == 1 {
				for l, r := 0, len(res[i])-1; l < r; l, r = l+1, r-1 {
					res[i][l], res[i][r] = res[i][r], res[i][l]
				}
			}
		}
	}

	return res
}

func zigzagLevelOrder(root *TreeNode) [][]int {
	return recur(root, true)
}
