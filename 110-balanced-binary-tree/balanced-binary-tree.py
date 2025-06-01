# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    ok = True

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def dfs(p: Optional[TreeNode]):
            if p == None:
                return 0
            left = dfs(p.left)
            right = dfs(p.right)
            if abs(right - left) >= 2:
                self.ok = False
            return max(right, left) + 1

        dfs(root)
        return self.ok
