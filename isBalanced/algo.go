package isbalanced

func max(i int, j int) int {
    if i > j {
        return i
    }
    return j
}

func abs(i int) int {
    if i < 0 {
        return -1 * i
    }
    return i
}

func depth(root *TreeNode) int {
    if root.Left == nil && root.Right == nil {
        return 1
    }
    lDep, rDep := 0, 0
    if root.Left != nil {
        lDep = depth(root.Left)
        if lDep == -1 {
            return -1
        }
    }
    if root.Right != nil {
        rDep = depth(root.Right)
        if rDep == -1 {
            return -1
        }
    }
    if abs(lDep - rDep) > 1 {
        return -1
    }
    return max(rDep, lDep) + 1
}

func isBalanced(root *TreeNode) bool {
    if root == nil {
        return true
    }
    return depth(root) > 0
}