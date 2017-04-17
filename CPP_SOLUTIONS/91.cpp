class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, 1);
        if(s.size() == 0) return s.size();
        s = " " + s;
        for(int i = 1; i < 2; i++) dp[i] = (s[i] != '0');
        for(int i = 2; i < s.size(); i++) {
            if(s[i - 1] == '1') dp[i] = dp[i - 1] * (s[i] != '0') + dp[i - 2];
            else if(s[i - 1] == '2' && s[i] <= '6') dp[i] = dp[i - 1] * (s[i] != '0') + dp[i - 2];
            else {
                if(s[i] == '0') return 0;
                dp[i] = dp[i - 1];
            }
        }
        return dp.back();
    }
};
