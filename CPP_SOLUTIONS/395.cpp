class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size() == 0) return 0;
        vector<int> count(256, 0);
        for(char c: s) count[c] ++;
        int i = 0;
        for(; i < s.size(); i++) {
            if(count[s[i]] < k) break;
        }
        if(i == s.size()) return i;
        int l = longestSubstring(s.substr(0, i), k);
        int r = longestSubstring(s.substr(i + 1), k);
        return max(l,r);
    }
};
