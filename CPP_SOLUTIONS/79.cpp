//79. Word Search

class Solution {
public:
    int h,w;
    bool go(vector<vector<char>>& board, string& word, int i, int x, int y) {
        if(x < 0 || x >= w || y < 0 || y >= h) return 0;
        if(board[y][x] != word[i]) return 0;
        if(i == word.size() - 1) return 1;
        board[y][x] = 0;
        bool res = go(board, word, i + 1, x - 1, y) || go(board, word, i + 1, x + 1, y) || go(board, word, i + 1, x, y - 1) || go(board, word, i + 1, x, y + 1);
        board[y][x] = word[i];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word == "") return 1;
        h = board.size();
        if(h == 0) return 0;
        w = board[0].size();
        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++) {
                if(go(board, word, 0, j, i)) return 1;
            }
        return 0;
    }
};
