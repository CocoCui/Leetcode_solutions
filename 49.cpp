#include <iostream>
#include <map>
#include <vector>

using namespace std;

class dic {
public:
    int c[26];
    dic() {
        memset(c, 0, sizeof(c));
    }
    bool operator < (const dic& d) const {
        return c[0] < d.c[0];
    }
};

map<dic,vector<string> > res;

vector<vector<string> > groupAnagrams(vector<string>& strs) {
    for(string s : strs) {
        dic d;
        for(char c : s)d.c[c] ++;
        res[d].push_back(s);
    }
    vector<vector<string> > r;
    for(auto p: res) {
        r.push_back(p.second);
    }
}

int main() {
}
