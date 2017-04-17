class Solution {
public:
    vector<string> res;
    void dfs(int l, int r, string p) {
        if(l == 0 && r == 0) {
            res.push_back(p);
            return;
        }
        if(l == 0) dfs(l, r - 1, p + ")");
        else {
            if(r > l) {
                dfs(l, r - 1, p + ")");
                dfs(l - 1, r, p + "(");
            } else dfs(l - 1, r, p + "(");
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        res.clear();
        dfs(n, n, "");
        return res;
    }
};
