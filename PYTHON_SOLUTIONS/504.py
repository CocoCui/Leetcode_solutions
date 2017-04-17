class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        s = ""
        if num == 0:
            return "0"
        if num < 0:
            sign = -1
            num = -num
        else:
            sign = 1
        while num:
            s = str(num % 7) + s
            num /= 7
        if sign < 0:
            s = "-" + s
        return s
        
