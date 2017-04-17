class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int l =  0;
        int maxlen = 0;
        for(int i = 0; i < s.size(); i++) {
            if(last[s[i]] >= l) {
                l = last[s[i]] + 1;
            }
            last[s[i]] = i;
            maxlen = max(i - l + 1, maxlen);
        }
        return maxlen;
    }
};
