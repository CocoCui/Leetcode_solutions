class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return vector<string>();
        vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res = {""}, tmp;
        for(char c: digits) {
            int n = c - '0';
            for(string s: res) 
                for(char cc: v[n]) 
                    tmp.push_back(s + cc);
            res = tmp;
            tmp.clear();
        }
        return res;
    }
};
