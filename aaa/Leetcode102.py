#https://leetcode.cn/problems/binary-tree-level-order-traversal/
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        ans = []
        queue = [root]
        index = 0
        while index < len(queue):
            level = []
            size = len(queue) - index
            for _ in range(size):
                node = queue[index]
                index += 1
                level.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            ans.append(level)
        return ans
