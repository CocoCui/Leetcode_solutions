#include<iostream>
#include<string>
using namespace std;
int t[256];
int lengthOfLongestSubstring(string s) {
    int l = 0, r = 0,len = strlen(s.c_str());
    int maxlen = 0;
    while(r < len) {
        while(t[s[r]] == 0 && r < len){
            //cout<<s[r]<<endl;
            t[s[r]]++;
            r++;
        }
        //cout<<l<<"--"<<r<<endl;
        maxlen = max(r - l , maxlen);
        while(s[l] != s[r]){
            t[s[l]]--;
            l++;
        }
        r++;
        l++;
    }
    return maxlen;
}

int main() {
    cout<<lengthOfLongestSubstring("au");
}
