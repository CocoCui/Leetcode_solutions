class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        d = n - m  + 1
        mask = 1
        time = 2
        res = 0
        
        while m * 2 > mask:
            cur = m % time
            if cur >= mask and cur + d <= time:
                res += mask;
            time *= 2
            mask *= 2
        return res;
        
