# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n == 0:
            return []
        def dfs(start, end):
            if start == end:
                return None
            result = []
            for i in xrange(start, end):
                for l in dfs(start, i) or [None]:
                    for r in dfs(i+1, end) or [None]:
                        node = TreeNode(i)
                        node.left, node.right  = l, r
                        result.append(node)
            return result
            
        return dfs(1, n +1)
        
