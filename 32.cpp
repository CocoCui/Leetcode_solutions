#include<iostream>

using namespace std;

int longestValidParentheses(string s) {
    int *dp = new int[s.size()];
    int left = 0, maxlen = 0;
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') left ++;
        else if(s[i] == ')' && left > 0){
            dp[i] = dp[i-1] + 2;
            if(i - dp[i] > 0) dp[i] += dp[i - dp[i]];
            left --;
            if(dp[i] > maxlen) maxlen = dp[i];
        }
        cout<<i<<" "<<dp[i]<<endl;
    }
    return maxlen;
}

int main() {
    cout<<longestValidParentheses("()()");
}
