#include<iostream>
#include<map>
#include<vector>
#include<unordered_set>

using namespace std;

void split(const string& src, const string separator, vector<string>& dest) {
    string str = src;
    string substring;
    string::size_type start = 0, index;
    do{
     index = str.find_first_of(separator,start);
     if (index != string::npos){    
         substring = str.substr(start,index-start);
         dest.push_back(substring);
        start = str.find_first_not_of(separator,index);
         if (start == string::npos) return;
     }
    }while(index != string::npos);
    
    //the last token
    substring = str.substr(start);
    dest.push_back(substring);
}
bool wordPattern(string pattern, string str) {
    string dic[30];
    unordered_set<string> strs;
    int id = 0;
    vector<string> words;
    split(str, " ", words);
    for(int i = 0; i < 30; i++) dic[i] = "";
    if(words.size() != pattern.size()) return 0;
    for(char c: pattern) {
        if(strs.find(words[id]) == strs.end()) {
            if(dic[c-'a'].size() == 0 ) {
                dic[c-'a'] = words[id];
                strs.insert(words[id]);
            }
            else {
                return 0;
            }
        }
        else {
            if(dic[c-'a'].size() && dic[c-'a'] == words[id]);
            else {
                return 0;
            }
        }
        id ++;
    }
    return 1;
}
int main() {
    int id = 1, a = 0;
    while(id < 2141483647 && a < 20) {
        a++;
        id = id * 4;
        cout<<id<<endl;
    }
}
