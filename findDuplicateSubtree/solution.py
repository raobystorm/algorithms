# Given the root of a binary tree, return all duplicate subtrees.
# For each kind of duplicate subtrees, you only need to return the root node of any one of them.
# Two trees are duplicate if they have the same structure with the same node values.

# Example 1:
# Input: root = [1,2,3,4,null,2,4,null,null,4]
# Output: [[2,4],[4]]

# Example 2:
# Input: root = [2,1,1]
# Output: [[1]]

# Example 3:
# Input: root = [2,2,2,3,null,3,null]
# Output: [[2,3],[3]]

# Constraints:
# The number of the nodes in the tree will be in the range [1, 10^4]
# -200 <= Node.val <= 200

from typing import List, Dict, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# Use serialization for a tree and hashmap to check if duplicate
class Solution:
    def dfs(self, root: Optional[TreeNode]) -> str:
        if root is None:
            return "."

        tmp = str(root.val) + "," + self.dfs(root.left) + "," + self.dfs(root.right)
        if tmp not in self.hashmap:
            self.hashmap[tmp] = 0
        self.hashmap[tmp] += 1
        if self.hashmap[tmp] == 2:
            self.res.append(root)
        return tmp

    def findDuplicateSubtrees(
        self, root: Optional[TreeNode]
    ) -> List[Optional[TreeNode]]:
        self.hashmap: Dict[str, int] = {}
        self.res: List[Optional[TreeNode]] = []
        self.dfs(root)
        return self.res