class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 0; i <= amount; i++) {
            for(int c: coins) {
                if(i - c >= 0) dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        if(dp[amount] > amount) return -1;
        else return dp[amount];
    }
};
