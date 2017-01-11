#include<unordered_map>
#include<iostream>

using namespace std;

int dp[4096][4096];

bool isOneEditDistance(string word1, string word2) {
    if(word1.size() == 0 || word2.size() == 0) return max(word1.size(), word2.size()) == 1;
    for(int j = 0; j <= word2.size(); j++) dp[0][j] = j;
    for(int i = 0; i < word1.size(); i++) {
        dp[(i+1)%2][0] = i+1;
        for(int j = 0; j < word2.size(); j++) {
            int c = 0;
            if(word1[i] != word2[j]) c++;
            dp[(i+1)%2][j+1] = min(dp[i%2][j+1] + 1, min(dp[(i+1)%2][j] + 1, dp[i%2][j] + c));
            cout<<i<<"-"<<j<<"-"<<dp[(i+1)%2][j+1]<<endl;
        }
    }
    cout<<dp[word1.size()%2][word2.size()]<<"12"<<endl;
    if(dp[word1.size()%2][word2.size()] == 1) return true;
    else return false;
}
int main(){
    cout<<isOneEditDistance("cb","ab"); 
}
