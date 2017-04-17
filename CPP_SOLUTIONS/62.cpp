class Solution {
public:
    int c(int m, int n) {
        long long ans = 1;
        int p = 1;
        for(int i = n + m - 2; i > max(n, m) - 1; i--) {
            ans *= i;
            ans /= p;
            p ++;
        }
        return ans;
    }
    int uniquePaths(int m, int n) {
        return c(m,n);
    }
};
