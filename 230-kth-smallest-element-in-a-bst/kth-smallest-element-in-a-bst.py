# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        self.ans = None
        self.cur = k
        def dfs(root):
            if self.ans or not root: return
            dfs(root.left)
            self.cur -= 1
            if(self.cur == 0):
                self.ans = root.val
            dfs(root.right)
        dfs(root)
        return self.ans
