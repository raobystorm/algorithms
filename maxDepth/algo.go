package maxdepth

func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    if root.Left == nil && root.Right == nil {
        return 1
    }
    
    lDep, rDep := 0, 0
    if root.Left != nil {
        lDep = maxDepth(root.Left)
    }
    if root.Right != nil {
        rDep = maxDepth(root.Right)
    }
    if lDep > rDep {
        return lDep+1
    }
    return rDep+1
}