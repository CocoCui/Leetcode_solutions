//329. Longest Increasing Path in a Matrix

class Solution {
public:
    int h, w;
    int res;
    int go(vector<vector<int>>& l, vector<vector<int>>& m, int x, int y, int last) {
        if(x < 0 || x >= w || y < 0 || y >= h) return 0;
        if(m[y][x] <= last) return 0;
        if(l[y][x]) return l[y][x];
        l[y][x] = 1;
        l[y][x] = max(l[y][x], 1 + go(l, m, x - 1, y, m[y][x]));
        l[y][x] = max(l[y][x], 1 + go(l, m, x + 1, y, m[y][x]));
        l[y][x] = max(l[y][x], 1 + go(l, m, x, y - 1, m[y][x]));
        l[y][x] = max(l[y][x], 1 + go(l, m, x, y + 1, m[y][x]));
        return l[y][x];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        h = matrix.size();
        if(h == 0) return 0;
        w = matrix[0].size();
        res = 0;
        vector<vector<int>> longest_path(h, vector<int>(w, 0));
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++) {
                //vector<vector<int>> visited(h, vector<int>(w, 0));
                res = max(res, go(longest_path, matrix, j, i, INT_MIN));
            }
        return res;
    }
};
