#include<sstream>
#include<iostream>

using namespace std;

int reverse(int x) {
    stringstream ss;
    string s1,s2 = "";
    ss << x;
    ss >> s1;
    int p = strlen(s1.c_str()) - 1;
    int start = 0;
    if(s1[0] == '-') {
        s2 += '-';
        start = 1;
    }
    while(p >= start) {
        s2 += s1[p];
        p --;
    }
    long a = atol(s2.c_str());
    if(a > INT_MAX || a < INT_MIN) return 0;
    else return (int)a;
}

int main() {
    cout<<reverse(-100);
}
