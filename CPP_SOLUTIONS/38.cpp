class Solution {
public:
    string i2s(int i) {
        stringstream ss;
        ss << i;
        string res;
        ss >> res;
        return res;
    }
    string countAndSay(int n) {
        string res = "1";
        for(int i = 1; i < n; i++) {
            int l = 0, r = 0;
            string tmp = "";
            while(l < res.size()) {
                while(r < res.size() && res[l] == res[r]) r ++;
                tmp += (to_string(r - l) + res[l]);
                l = r;
            }
            res = tmp;
        }
        return res;
    }
};
