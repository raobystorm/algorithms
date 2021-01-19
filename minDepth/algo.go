package mindepth

func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    if root.Left == nil && root.Right == nil {
        return 1
    }
    if root.Left == nil {
        return minDepth(root.Right)+1
    }
    if root.Right == nil {
        return minDepth(root.Left)+1
    }
    lDep := minDepth(root.Left)
    rDep := minDepth(root.Right)
    if lDep < rDep {
        return lDep+1
    }
    return rDep+1
}