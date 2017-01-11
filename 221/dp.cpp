#include<iostream>
#include<vector>

using namespace std;

int maximalSquare(vector<vector<char> >& matrix) {
    vector<vector<int> > m;
    int maxs = 0;
    for(int i = 0; i < matrix.size(); i++) {
        vector<int> v;
        m.push_back(v);
        for(int j = 0; j < matrix[i].size(); j++) {
            m[i].push_back((matrix[i][j] == '1'));
            if(matrix[i][j] == '1') maxs = 1;
        }
    }
    for(int i = 1; i < matrix.size(); i ++) {
        for(int j = 1; j < matrix[i].size(); j++) {
            if(m[i][j] > 0) {
                m[i][j] = min(m[i-1][j-1],min(m[i-1][j], m[i][j-1])) + 1;
            }
            if(m[i][j] > maxs) maxs = m[i][j];
        }
    }
    cout<<"------------------"<<endl;
    for(int i = 0; i < matrix.size(); i ++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    return maxs * maxs;
}
int main() {
    vector<vector<char> > ma;
    string a = "00011101111101110111";
    int id = 0;
    for(int i = 0; i < 5; i++) {
        vector<char> v;
        for(int j =0; j < 4; j++){
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
    maximalSquare(ma);
}
