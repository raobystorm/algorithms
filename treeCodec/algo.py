from typing import List


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:

    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return '[]'
        # res_list: List[Union[int, None]]
        res: str = '['
        # queue: List[Union[TreeNode, None]]
        queue: List = [root]
        i = 0
        while i < len(queue):
            curr = queue[i]
            if curr is not None:
                res += f'{curr.val},'
                if curr.left is not None:
                    queue.append(curr.left)
                else:
                    queue.append(None)
                if curr.right is not None:
                    queue.append(curr.right)
                else:
                    queue.append(None)
            else:
                res += 'null,'
            i += 1
        res = res[:-1]
        res += ']'
        return res

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        data = data.replace('\n', '')
        if data == '[null]' or data == '[]':
            return None
        data = data[1:-1]
        vals: List[str] = data.split(',')
        queue: List[TreeNode] = [TreeNode(vals[0])]
        head = queue[0]
        del vals[0]
        while len(queue) > 0 and len(vals) > 0:
            curr_node = queue[0]
            queue = queue[1:]
            left = vals[0]
            vals = vals[1:]
            right = None
            if len(vals) > 0:
                right = vals[0]
                vals = vals[1:]
            if left != 'null':
                curr_node.left = TreeNode(int(left))
                queue.append(curr_node.left)
            if right is not None and right != 'null':
                curr_node.right = TreeNode(int(right))
                queue.append(curr_node.right)
        return head
