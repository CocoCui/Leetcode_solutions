class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums:
            return [-1, -1]
        def lower(tar):
            l,r = 0,len(nums)-1
            while l <= r:
                mid = (l + r) / 2
                if nums[mid] < tar:
                    l = mid + 1
                else:
                    r = mid - 1
            return l
        
        l,r = lower(target), lower(target + 1) - 1
        #print l,r
        if l >= len(nums) or nums[l] != target:
            return [-1,-1]
        else:
            return [l,r]
