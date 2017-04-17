class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> c(nums.size(), 1);
        int maxlen = 1;
        for(int i = 1; i < nums.size(); i++)
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    c[i] = max(c[i], c[j] + 1);
                    maxlen = max(maxlen, c[i]);
                }
            }
        return maxlen;
    }
};
