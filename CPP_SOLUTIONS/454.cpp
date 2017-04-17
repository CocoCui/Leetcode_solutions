class Solution {
public:
    unordered_map<int, int> ab;
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        for(int a: A)
            for(int b: B){
                ab[a+b] ++;
            }
        for(int c: C)
            for(int d: D) {
                int sum = c + d;
                res += ab[-sum];
            }
        return res;
    }
};
