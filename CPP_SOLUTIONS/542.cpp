// 542. 01 Matrix
class Solution {
public:
    queue<pair<int, int>> q;
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int h = matrix.size();
        if(h == 0) return matrix;
        int w = matrix[0].size();
        for(int i = 0; i < h; i ++)
            for(int j = 0; j < w; j++)
                if(matrix[i][j] == 1) matrix[i][j] = INT_MAX;
                else {
                    q.push(make_pair(i,j));
                }
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i > 0) {
                if (matrix[i - 1][j] == INT_MAX) q.push(make_pair(i - 1, j));
                matrix[i - 1][j] = min(matrix[i - 1][j], matrix[i][j] + 1);
            }
            if (i < h - 1) {
                if (matrix[i + 1][j] == INT_MAX) q.push(make_pair(i + 1, j));
                matrix[i + 1][j] = min(matrix[i + 1][j], matrix[i][j] + 1);
            }
            if (j > 0) {
                if (matrix[i][j - 1] == INT_MAX) q.push(make_pair(i, j - 1));
                matrix[i][j - 1] = min(matrix[i][j - 1], matrix[i][j] + 1);
            }
            if (j < w - 1) {
                if (matrix[i][j + 1] == INT_MAX) q.push(make_pair(i, j + 1));
                matrix[i][j + 1] = min(matrix[i][j + 1], matrix[i][j] + 1);
            }
        }
        return matrix;
    }
};
