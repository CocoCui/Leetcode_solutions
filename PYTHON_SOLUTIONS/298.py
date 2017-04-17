# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def longestConsecutive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.maxlen = 0
        def dfs(root):
            if not root:
                return
            lc = rc = 1
            if root.left:
                if root.val + 1 == root.left.val:
                    lc = dfs(root.left) + 1
                else:
                    dfs(root.left)
            if root.right:
                if root.val + 1 == root.right.val:
                    rc = dfs(root.right) + 1
                else:
                    dfs(root.right)
            #print(root.val, lc, rc)
            self.maxlen = max([lc, rc, self.maxlen])
            return max(lc,rc)
        dfs(root)
        return self.maxlen
