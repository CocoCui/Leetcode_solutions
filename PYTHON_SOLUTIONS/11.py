class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l,r = 0, len(height) - 1
        res = 0
        while l < r:
            mh = min(height[l], height[r])
            res = max(res, (r - l) * mh)
            while(l < r and height[l] <= mh):
                l += 1
            while(r > l and height[r] <= mh):
                r -= 1
        return res
