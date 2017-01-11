#include <iostream>

using namespace std;

string convert(string s, int numRows) {
    string ans = "";
    int len = strlen(s.c_str());
    int c = numRows + max((numRows - 2), 0);
    int t = strlen(s.c_str()) / c + (strlen(s.c_str()) % c != 0);
    for(int r = 0; r < numRows; r ++) {
        for(int i = 0; i < t; i ++) {
            if(r == 0 || r == numRows - 1) {
                int idx = c * i + r;
                if(idx < len) ans += s[idx];
            } else {
                int idx1 = c * i + r, idx2 = c * i + c - r;
                if(idx1 < len) ans += s[idx1];
                if(idx2 < len) ans += s[idx2];
            }
        }
    }
    return ans;
}

int main() {
    cout<<convert("PAYPALISHIRING", 3);
}
