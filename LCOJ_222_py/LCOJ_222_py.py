class TreeNode:
     def __init__(self, x):
         self.val = x
         self.left = None
         self.right = None

class Solution:
    # @param {TreeNode} root
    # @param {integer} height: the height of root node - 
    def compareLR(self, node):
        leftCount = 0
        rightCount = 0
        if node is None:
            return 0, 0
        leftCount = 1
        rightCount = 1
        left = node.left
        right = node.right
        while(left is not None):
            leftCount = leftCount + 1
            left = left.left
        while(right is not None):
            rightCount = rightCount + 1
            right = right.right
        return leftCount, rightCount
    
    # @return {integer} returns the 
    def trackUnbalanced(self, node, leftCount, rightCount):
        if leftCount == rightCount:
            return 2**leftCount-1

        leftleft, leftright = self.compareLR(node.left)
        rightleft, rightright = self.compareLR(node.right)

        if leftleft != leftright:
            return self.trackUnbalanced(node.left, leftleft, leftright) + 2**rightleft
        if rightleft != rightright:
            return self.trackUnbalanced(node.right, rightleft, rightright) + 2**leftleft
        else:
            return 2**leftleft-1+2**rightleft

    # @param {TreeNode} root
    # @return {integer}
    def countNodes(self, root):
        if root is None:
            return 0
        ptr = root
        leftCount = 0
        rightCount = 0
        leftCount, rightCount = self.compareLR(ptr)
        # if it is completed on last layer
        if leftCount == rightCount:
            return 2**leftCount-1

        return self.trackUnbalanced(root, leftCount, rightCount)

t1 = TreeNode(1)
t2 = TreeNode(2)
t3= TreeNode(3)
t4= TreeNode(4)
t5= TreeNode(5)
t6= TreeNode(6)
t7= TreeNode(7)
t8 = TreeNode(8)

t1.left = t2
t1.right = t3
t2.left = t4
t2.right = t5
t3.left = t6
t3.right = t7

print(Solution().countNodes(t1))