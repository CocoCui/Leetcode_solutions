class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l,r = 1,len(nums) - 1
        while l != r:
            less = 0
            bigger = 0
            equal = 0
            mid = (l + r) / 2
            for i in nums:
                if i < mid and r >= l:
                    less += 1
                elif i > mid and i <= r:
                    bigger += 1
                elif i == mid:
                    equal += 1
            #print(mid, less, bigger, equal)
            if equal > 1:
                return mid
            if bigger > r - mid:
                l = mid + 1
            else:
                r = mid - 1
            #print(l,r)
        return l
