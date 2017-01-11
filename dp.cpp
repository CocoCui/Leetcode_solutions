#include<iostream>
#include<vector>
using namespace std;
int minimumTotal(vector<vector<int> >& triangle) {
    vector<int> mintot;
    for(int i = 0; i < triangle.size(); i++) mintot.push_back(0);
    mintot.push_back(triangle[0][0]);
    for(int i = 0; i < triangle.size(); i++) {
        int temp = mintot[0];
        for(int j = 0; j < triangle[i].size(); j++){
            if(j > 0) temp = mintot[j-1];
            if(j > 0 && j < triangle[i].size() - 1) {
                mintot[j] = triangle[i][j] + min(temp, mintot[j]);
            } else if(j == 0) {
                mintot[j] = triangle[i][j] + mintot[j];
            } else if(j == triangle[i].size() - 1) {
                mintot[j] = triangle[i][j] + temp;
            }
        }
    }
    int minc = 2147483647;
    for(int i = 0; i < triangle.size(); i++) {
        if(mintot[i] < minc) minc = mintot[i];
    }
    return minc;
}
int main() {
}
