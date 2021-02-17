package haspathsum

func hasPathSum(root *TreeNode, targetSum int) bool {
    if root == nil {
        return false
    }
    if root.Val == targetSum && root.Left == nil && root.Right == nil {
        return true
    }
    
    left := hasPathSum(root.Left, targetSum - root.Val)
    right := hasPathSum(root.Right, targetSum - root.Val)
    
    return left || right
}