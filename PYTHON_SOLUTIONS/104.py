# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def dfs(self, root, deep):
        if root == None:
            return deep
        return max(self.dfs(root.left, deep + 1), self.dfs(root.right, deep + 1))
        
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.dfs(root, 0)
    
        
