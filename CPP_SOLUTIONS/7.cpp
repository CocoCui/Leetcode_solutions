class Solution {
public:
    
    int reverse(int x) {
        long long a = x;
        int sign = 1;
        if(a < 0) {
            a = -a;
            sign = -1;
        }
        vector<int> v;
        while(a) {
            v.push_back(a % 10);
            a /= 10;
        }
        long long p = 1;
        long long res = 0;
        for(int i = v.size() - 1; i >= 0; i--) {
            res += (p * v[i]);
            p *= 10;
        }
        res *= sign;
        if(res < INT_MIN || res > INT_MAX) return 0;
        return res;
        
    }
};
