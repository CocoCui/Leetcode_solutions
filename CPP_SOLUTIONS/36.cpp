class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9,vector<int>(10, 0)), col(9,vector<int>(10, 0)), cube(9,vector<int>(10, 0));
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                if(row[i][num] != 0) return 0;
                if(col[j][num] != 0) return 0;
                int cubeidx = j / 3 + (i / 3) * 3;
                if(cube[cubeidx][num] != 0) return 0;
                row[i][num] ++;
                col[j][num] ++;
                cube[cubeidx][num] ++;
            }
        return 1;
    }
}
