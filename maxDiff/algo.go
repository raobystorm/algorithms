package maxdiff

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Diff struct {
	min  int
	max  int
	diff int
}

func compDiff(d1 Diff, d2 Diff, val int) Diff {
	res := Diff{}
	if d1.min < d2.min {
		res.min = d1.min
	} else {
		res.min = d2.min
	}
	if d1.max > d2.max {
		res.max = d1.max
	} else {
		res.max = d2.max
	}
	maxDiff := d1.diff
	if d2.diff > maxDiff {
		maxDiff = d2.diff
	}
	if val-res.min > maxDiff {
		maxDiff = val - res.min
	}
	if res.max-val > maxDiff {
		maxDiff = res.max - val
	}
	res.diff = maxDiff
	return res
}

func maxDiff(r *TreeNode) Diff {
	diff := Diff{r.Val, r.Val, 0}
	if r.Left == nil && r.Right == nil {
		return diff
	}
	if r.Left != nil {
		diff = compDiff(diff, maxDiff(r.Left), r.Val)
	}
	if r.Right != nil {
		diff = compDiff(diff, maxDiff(r.Right), r.Val)
	}
	return diff
}

func maxAncestorDiff(r *TreeNode) int {
	res := maxDiff(r)
	return res.diff
}
