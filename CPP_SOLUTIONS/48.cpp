class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n < 2) return;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j++) 
                m[j][n - 1 - i] = matrix[i][j];
        matrix = m;
        return;
    }
};
