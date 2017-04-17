class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        int sign = 1;
        if(n < 0) {
            n = -n;
            sign = -1;
        }
        double r = 1;
        while(n) {
            if(n % 2) r *= x;
            n /= 2;
            x *= x;
        }
        if(sign > 0) return r;
        else return 1 / r;
    }
};
