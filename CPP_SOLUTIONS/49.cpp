class Solution {
public:
    string sort(string& s) {
        vector<int> count(256, 0);
        for(char c: s) {
            count[c] ++;
        }
        string res = "";
        for(int a = 'a'; a <= 'z'; a++) 
            for(int j = 0; j < count[a]; j++) res += char(a);
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> m;
        vector<vector<string>> res;
        for(string str: strs) {
            string org = str;
            str = sort(str);
            if(m.find(str) != m.end()) {
                res[m[str]].push_back(org);
            } else {
                m[str] = res.size();
                res.push_back(vector<string>());
                res.back().push_back(org);
            }
        }
        return res;
    }
};
