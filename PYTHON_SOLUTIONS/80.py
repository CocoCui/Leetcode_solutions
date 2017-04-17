class Solution(object):
    def removeDuplicates(self, num):
        """
        :type nums: List[int]
        :rtype: int
        """
        l,r,c = 0,1,1
        n = len(num)
        if n < 3:
            return n
        while l < n and r < n:
            #print(l, r, c)
            if num[r] == num[l]:
                if r - l < 2:
                    num[c] = num[r]
                    c += 1
                r += 1
            else:
                num[c] = num[r]
                c += 1
                l += 1
                r += 1
        print(c)
        return c
