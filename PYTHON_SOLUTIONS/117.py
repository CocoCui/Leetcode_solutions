# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None
from collections import deque
class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if not root:
            return
        que = deque()
        que.append((root, 0))
        cur = -1
        while que:
            node, depth = que.popleft()
            if not node:
                continue
            if depth > cur:
                cur = depth
                pre = None
            node.next = None
            if pre:
                pre.next = node
            pre = node
            que.append((node.left, depth + 1))
            que.append((node.right, depth + 1))
        return
            
        
