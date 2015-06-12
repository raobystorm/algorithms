# Definition for a binary tree node.

class TreeNode:
    def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {TreeNode}
    def invertTree(self, root):
        if root is None:
            return None
        tmp = root.left
        root.left = root.right
        root.right = tmp
        if root.left is not None:
            self.invertTree(root.left)
        if root.right is not None:
            self.invertTree(root.right)
        return root

    def printTree(self, root):
        if root.left is not None:
            self.printTree(root.left)

        print(root.val)

        if root.right is not None:
            self.printTree(root.right)


node = TreeNode(1)

Solution().printTree(Solution().invertTree(node)) 