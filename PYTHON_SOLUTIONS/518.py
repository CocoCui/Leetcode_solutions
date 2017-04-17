class Solution(object):
    def change(self, amount, coins):
        """
        :type amount: int
        :type coins: List[int]
        :rtype: int
        """
        sum = [0] * (amount + 1)
        sum[0] = 1
        for c in coins:
            for i in range(1,amount + 1):
                if i - c >= 0:
                    sum[i] += sum[i - c]
        #print(sum)
        return sum[amount]
        
