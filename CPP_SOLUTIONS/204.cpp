class Solution {
public:
    int countPrimes(int n) {
        if(n < 3) return 0;
        vector<int> p(n,1);
        int base = 2;
        while(base < n) {
            for(int i = base * 2; i < n; i += base) p[i] = 0;
            while(base < n && p[++base] == 0) {}
        }
        int count = 0;
        for(int i = 2; i < n; i++) count += p[i];
        return count;
    }
};
