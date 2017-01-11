#include<iostream>
#include<vector>

using namespace std;

int h, w, c = 0;
void dfs(int x, int y, vector<vector<char> >& grid) {
    if(x < 0 || x >= w) {
        return;
    }
    if(y < 0 || y >= h) {
        return;
    }
    if(grid[y][x] == '1') {
        grid[y][x] = '0';
        dfs(x - 1, y, grid);
        dfs(x + 1, y, grid);
        dfs(x, y - 1, grid);
        dfs(x, y + 1, grid);
    }
    return;
}
int numIslands(vector<vector<char> >& grid) {
    vector<int> x,y;
    h = grid.size();
    if(h) w = grid[0].size();
    else w = 0;
    cout<<w<<"--"<<h<<endl;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(grid[i][j] == '1') {
                y.push_back(i);
                x.push_back(j);
            }
        }
    }
    for(int i = 0; i < x.size(); i++) {
        if(grid[y[i]][x[i]] == '1') {
            c++;
            dfs(x[i],y[i], grid);
        }
    }
    return c;
}

int main() {
    vector<vector<char> > ma;
    string a = "1011011";
    int id = 0;
    for(int i = 0; i < 1; i++) {
        vector<char> v;
        for(int j =0; j < 7; j++){
            v.push_back(a[id]);
            id ++;
        }
        ma.push_back(v);
    }
    for(int i = 0; i < ma.size(); i ++) {
        for(int j = 0; j < ma[i].size(); j++) {
            cout<<ma[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<numIslands(ma);
}
