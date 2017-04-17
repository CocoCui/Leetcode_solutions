class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = (l + r) / 2;
            if(mid < nums.size() - 1 && nums[mid] < nums[mid + 1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
