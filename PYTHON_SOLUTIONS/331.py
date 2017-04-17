class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        stack = []
        if preorder == "#":
            return True
        vals = preorder.split(",")
        for i in range(len(vals)):
            if vals[i] != "#":
                if len(stack):
                    stack[-1] -= 1
                    if(stack[-1] == 0):
                        stack.pop()
                stack.append(2)
            else:
                if len(stack):
                    stack[-1] -= 1
                    if stack[-1] == 0:
                        stack.pop()
            #print(vals[i],stack)
            if len(stack) == 0:
                return i == len(vals) - 1
        return False;
