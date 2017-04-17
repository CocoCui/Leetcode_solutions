class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        dp = [1] * (len(s) + 1)
        if not s or s[0] == "0":
            return 0
        for i in range(2, len(s) + 1):
            dp[i] = 0
            if s[i-1] > '0':
                dp[i] += dp[i-1]
            if 9 < int(s[i-2:i]) < 27 :
                dp[i] += dp[i-2]
            #print(s[i - 1], dp[i])
        #print dp
        return dp[-1]
                
            
