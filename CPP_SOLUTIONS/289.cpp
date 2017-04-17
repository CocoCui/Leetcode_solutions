class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int h = board.size();
        if(h == 0) return;
        int w = board[0].size();
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++) {
                int nei = 0;
                for(int k = -1; k <= 1; k++)
                    for(int l = -1; l <= 1; l++) {
                        if(k == 0 && l == 0) continue;
                        if(i + k < 0 || i + k == h || j + l < 0 || j + l == w) continue;
                        if(board[i + k][j + l] % 2) nei ++;
                    }
                if(board[i][j] == 1) {
                    if(nei == 2 || nei == 3) board[i][j] += 2;
                } else {
                    if(nei == 3) board[i][j] += 2;
                }
            }
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                if(board[i][j] > 1) board[i][j] = 1;
                else board[i][j] = 0;
        return;
            
    }
};
