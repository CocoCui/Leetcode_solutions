class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> dict;
        for(string s: wordDict) dict[s] = 1;
        vector<int> dp(s.size(), 0);
        int n = s.size();
        for(int i = 1; i <= n; i++) {
            if(dict[s.substr(0, i)]) dp[i-1] = 1;
        }
        //for(int i = 0; i < n; i ++) cout << dp[i];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++) {
                if(dp[j] && dict[s.substr(j + 1, i - j)] == 1) dp[i] = 1;
            }
        return dp[n - 1];
    }
};
