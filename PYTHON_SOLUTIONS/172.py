class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        f = 5
        count = 0
        while n:
            count += n / 5
            n /= 5
        return count