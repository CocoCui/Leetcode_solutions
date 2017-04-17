# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def countUnivalSubtrees(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.res = 0
        if not root:
            return 0
        def dfs(root):
            if not root:
                self.res -= 1
                return True
            l = dfs(root.left)
            r = dfs(root.right)
            self.res = self.res + l + r
            if l and r:
                if root.left:
                    if root.right:
                        return root.val == root.left.val and root.val == root.right.val
                    else:
                        return root.val == root.left.val
                else:
                    if root.right:
                        return root.val == root.right.val
                    else:
                        return True
            else:
                return False
                
        if dfs(root):
            self.res += 1
        return self.res
                    
