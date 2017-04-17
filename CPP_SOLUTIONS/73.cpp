class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = 0, col = 0;
        int h = matrix.size();
        if(h == 0) return;
        int w = matrix[0].size();
        for(int i = 0; i < h; i++) 
            if(matrix[i][0] == 0) {
                col = 1;
                break;
            }
        for(int j = 0; j < w; j++) {
            if(matrix[0][j] == 0) {
                row = 1;
                break;
            }
        }
        for(int i = 1; i < h; i++) {
            for(int j = 1; j < w; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < h; i++) 
            if(matrix[i][0] == 0) {
                for(int j = 1; j < w; j++) matrix[i][j] = 0;
            }
        for(int j = 1; j < w; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < h; i++) matrix[i][j] = 0;
            }
        }
        if(row) for(int i = 0; i < w; i++) matrix[0][i] = 0;
        if(col) for(int i = 0; i < h; i++) matrix[i][0] = 0;
    }
};
