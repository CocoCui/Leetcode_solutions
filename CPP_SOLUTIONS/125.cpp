class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for(char c: s) {
            if(c >= '0' && c <= '9') res += c;
            if(c >= 'a' && c <= 'z') res += c;
            if(c >= 'A' && c <= 'Z') res += char('a' + c - 'A');
        }
        for(int i = 0; i < res.size()/2; i++) {
            if(res[i] != res[res.size() - 1 - i]) return 0;
        }
        return 1;
    }
};
