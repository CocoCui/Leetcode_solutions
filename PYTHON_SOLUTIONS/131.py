class Solution(object):
    res = []
    stack = []
    
    def isPalindrome(self, s):
        #print(s)
        for i in range(len(s)/2):
            if s[i] != s[-i-1]:
                return False
        return True
    
    def dfs(self, s, idx):
        n = len(s)
        #print idx
        if idx == n:
            #print self.stack
            self.res.append(list(self.stack))
            return
        for l in range(1, len(s) - idx + 1):
            #print(s[idx: idx + l], self.isPalindrome(s[idx: idx + l]))
            if self.isPalindrome(s[idx: idx + l]):
                #print(s[idx: idx + l])
                self.stack.append(s[idx: idx + l])
                self.dfs(s, idx + l)
                self.stack.pop()
    
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        self.res = []
        self.stack = []
        self.dfs(s, 0)
        return self.res
        
