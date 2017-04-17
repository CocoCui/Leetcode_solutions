import random
class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.org = list(nums)

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        return self.org
        

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        l = list(self.org)
        n = len(l)
        for i in range(n):
            r = random.randint(i,n - 1)
            l[i], l[r] = l[r], l[i]
        return l
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
