package sortedarraytobst

func sortedArrayToBST(nums []int) *TreeNode {
    if len(nums) == 0 {
        return nil
    }
    
    if len(nums) == 1 {
        return &TreeNode{nums[0], nil, nil}
    }
    
    piv := len(nums)/2    
    return &TreeNode{nums[piv], sortedArrayToBST(nums[:piv]), sortedArrayToBST(nums[piv+1:])}
}