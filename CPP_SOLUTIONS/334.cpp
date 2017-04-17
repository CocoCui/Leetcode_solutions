class Solution {
public:

    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX, mid = INT_MAX;
        for(int n: nums) {
            if(n <= min) min = n;
            else if (n <= mid) mid = n;
            else return 1;
        }
        return 0;
    }
};
