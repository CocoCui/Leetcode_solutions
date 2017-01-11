#include<iostream>
#include<string>

using namespace std;
int len[100000];
string longestPalindrome(string s) {
    memset(len, 0, sizeof(int) * 100000);
    string ss = "%#";
    for(auto c : s) {
        ss += c;
        ss += "#";
    }
    ss += "!";
    cout<<ss<<endl;

    int mx = 0, ans = 0, po = 0, sign;
    for(int i = 1; i < strlen(ss.c_str()); i++) {
        if(mx > i) len[i] = min(mx - i, len[2 * po - i]);
        else len[i] = 1;
        while(ss[i - len[i]] == ss[i + len[i]]) len[i] ++;
        if(len[i] + i > mx) {
            mx = len[i] + i;
            po = i;
        }
        if(len[i] > ans) {
            ans = len[i];
            sign = i;
        }
    }
    string subs = "";
    for(int i = max(1, sign - ans + 1); i < min((int)strlen(ss.c_str()) - 1, sign + ans); i ++) {
        if(ss[i] != '#') subs += ss[i];
    }
    return subs;
}

int main() {
    cout<<longestPalindrome("hehe"); 
}
