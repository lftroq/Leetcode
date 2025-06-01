# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        stack = [(root, -10 ** 14, 10 ** 14)]
        while stack:
            node, minVal, maxVal = stack.pop()

            if not node:
                continue
            if not (minVal < node.val < maxVal):
                return False

            stack.append((node.left, minVal, node.val))
            stack.append((node.right, node.val, maxVal))
        return True
