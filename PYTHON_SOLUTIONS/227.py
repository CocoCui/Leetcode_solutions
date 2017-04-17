class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        s = s.replace(" ", "")
        l,r = 0,1
        sign = 1 
        stack = []
        while l < len(s):
            if s[l].isdigit():
                while r < len(s) and s[r].isdigit():
                    r += 1
                num = int(s[l:r])
                stack.append(num * sign)
            elif s[l] == "+":
                sign = 1
            elif s[l] == "-":
                sign = -1
            else:
                op = s[l]
                lv = stack.pop()
                l += 1
                r = l + 1
                while r < len(s) and s[r].isdigit():
                    r += 1
                num = int(s[l:r])
                #print(lv, op, num)
                if op == "*":
                    stack.append(lv * num)
                else:
                    stack.append(abs(lv) / num * (1 if lv > 0 else -1))
            l = r
            r += 1
            #print(stack)
        return sum(stack)
                
            
        
