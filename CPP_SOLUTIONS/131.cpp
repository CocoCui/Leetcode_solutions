class Solution {
public:
    vector<vector<string>> res;
    vector<string> tmp;
    bool Palindrome(string s) {
        for(int i = 0; i < s.size() / 2; i++) if(s[i] != s[s.size() - 1 - i]) return 0;
        return 1;
    } 
    void dfs(string s) {
        if(s.size() == 0) {
            res.push_back(tmp);
            return;
        }
        for(int i = 1; i <= s.size(); i++) {
            if(Palindrome(s.substr(0, i))) {
                //cout << s.substr(0, i) << endl;
                tmp.push_back(s.substr(0, i));
                dfs(s.substr(0 + i));
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        res.clear();
        tmp.clear();
        if(s == "") return res;
        dfs(s);
        return res;
    }
};
