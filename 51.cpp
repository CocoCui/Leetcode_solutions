#include<iostream>
#include<vector>

using namespace std;
int xx[1000], l1[1000], l2[1000];

vector<vector<string> > res;
int n;

class Solution {
public:
    
    void dfs(int y, vector<pair<int, int> > cors) {
        if(y == n + 1) {
            string line;
            vector<string> ss;
            for(int i = 0; i < n; i++) line += '.';
            for(int i = 0; i < n; i++) ss.push_back(line);
            for(auto c : cors) {
                int x = c.first, y = c.second;
                ss[y-1][x-1] = 'Q';
            }
            res.push_back(ss);
            return;
        }
        for(int i = 1; i <= n; i++) {
            if(xx[i] == 0 && l1[i + y] == 0 && l2[i - y + n] == 0) {
                cors.push_back(make_pair(y, i));
                xx[i] = 1;
                l1[i + y] = 1;
                l2[i - y + n] = 1;
                dfs(y + 1, cors);
                xx[i] = 0;
                l1[i + y] = 0;
                l2[i - y + n] = 0;
                cors.pop_back();
            }
        }
        return;
    }
    vector<vector<string> > solveNQueens(int nn) {
        n = nn;
        memset(xx, 0, sizeof(xx));
        memset(l1, 0, sizeof(l1));
        memset(l2, 0, sizeof(l2));
        vector<pair<int, int> > cors;
        cors.clear();
        res.clear();
        dfs(1, cors);
        return res;
    }
};

int main() {
    Solution s;
    s.solveNQueens(4); 
}

