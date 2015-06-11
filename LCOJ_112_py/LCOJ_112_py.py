
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} node
    # @param {integer} sum
    def dfs(self, node, sum):
        if node is None:
            return False
        if node.val == sum and node.left is None and node.right is None:
            return True

        return self.dfs(node.left, sum - node.val) or self.dfs(node.right, sum - node.val)
    # @param {TreeNode} root
    # @param {integer} sum
    # @return {boolean}
    def hasPathSum(self, root, sum):
        return self.dfs(root, sum)
        