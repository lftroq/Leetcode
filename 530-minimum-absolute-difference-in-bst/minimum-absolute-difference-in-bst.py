# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        stack, node = [], root
        prev, ans = -100000, 200000
        while True:
            while node:
                stack.append(node)
                node = node.left
            if not stack:
                break
            node = stack.pop()
            ans = min(ans, node.val - prev)
            prev = node.val
            node = node.right
        return ans
