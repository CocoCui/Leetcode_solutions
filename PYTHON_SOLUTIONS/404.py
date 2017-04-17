# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.res = 0
        def dfs(root, d):
            if not root:
                return 0
            if d:
                if not root.right and not root.left:
                    self.res += root.val
            dfs(root.right, False)
            dfs(root.left, True)
        
        dfs(root,False)
        return self.res;
