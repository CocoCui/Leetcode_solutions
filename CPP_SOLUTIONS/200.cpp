class Solution {
public:
    int h, w;
    void dfs(vector<vector<char>>& grid, int y, int x) {
        if( y < 0 || y >= h || x < 0 || x >= w) return;
        if(grid[y][x] == '0') return;
        grid[y][x] = '0';
        dfs(grid, y, x - 1);
        dfs(grid, y, x + 1);
        dfs(grid, y + 1, x);
        dfs(grid, y - 1, x);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        h = grid.size();
        if(h == 0) return 0;
        w = grid[0].size();
        int count = 0;
        for(int i = 0; i <  h; i++)
            for(int j = 0; j < w; j++)
                if(grid[i][j] == '1') {
                    count ++;
                    dfs(grid, i, j);
                }
        return count;
    }
};
