//152. Maximum Product Subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        int maxp = nums[0];
        vector<int> ma(n, nums[0]), mi(n, nums[0]);
        for(int i = 1; i < nums.size(); i++) {
            ma[i] = max(nums[i], max(nums[i] * ma[i - 1], nums[i] * mi[i - 1]));
            mi[i] = min(nums[i], min(nums[i] * ma[i - 1], nums[i] * mi[i - 1]));
            maxp = max(maxp, ma[i]);
        }
        return maxp;
    }
};
