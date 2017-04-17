# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        l = []
        while head:
            l.append(head.val)
            head = head.next
        def buildTree(head):
            #print(head)
            if not head:
                return None
            m = head[len(head)/2]
            root = TreeNode(m)
            root.right = buildTree(head[len(head)/2 + 1:])
            root.left = buildTree(head[:len(head)/2])
            return root
        return buildTree(l)
        
