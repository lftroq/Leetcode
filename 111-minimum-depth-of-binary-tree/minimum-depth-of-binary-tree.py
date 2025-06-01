# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        queue = deque([[root, 1]])

        while queue:
            u, d = queue.popleft()
            if not u.left and not u.right:
                return d
            if u.left:
                queue.append([u.left, d + 1])
            if u.right:
                queue.append([u.right, d + 1])
