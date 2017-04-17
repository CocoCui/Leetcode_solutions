class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = "1"
        for i in range(n-1):
            j, n= 0,0
            tmp = ""
            while j < len(s):
                c = 0
                while n < len(s) and s[j] == s[n]:
                    n += 1
                    c += 1
                tmp = tmp + str(c) + s[j]
                j = n
            s = tmp
        return s
        
        
