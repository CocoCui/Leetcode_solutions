# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        if not inorder:
            return None
        root = TreeNode(postorder[-1])
        l = inorder.index(root.val)
        root.left = self.buildTree(inorder[0:l],postorder[0:l])
        root.right = self.buildTree(inorder[l + 1:], postorder[l:-1])
        return root
        
