# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        if not root:
            return None
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        else:
            if not root.left and not root.right:
                return None
            elif root.left == None:
                return root.right
            elif root.right == None:
                return root.left
            else:
                lr = root.left
                while lr.right:
                    lr = lr.right
                root.val = lr.val
                root.left = self.deleteNode(root.left, lr.val)
        return root
        
