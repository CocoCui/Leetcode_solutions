#include<iostream>
#include<vector>
using namespace std;
char pt[256];
bool isValid(string s) {
    vector<char> ps;
    pt['['] = ']';
    pt['{'] = '}';
    pt['('] = ')';
    for(int i = 0; i < strlen(s.c_str()); i++) {
        if(ps.empty()) ps.push_back(s[i]);
        else if( s[i] == pt[ps[ps.size() - 1]] ) ps.pop_back();
        else ps.push_back(s[i]);
    }
    if(ps.empty()) return true;
    else return false;
}

int main() {
    cout<<isValid("()[](}");
}
