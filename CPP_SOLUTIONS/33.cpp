class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] == target) return mid;
            else if(target < nums[mid]) {
                if(nums[mid] > nums[l]) {
                    if(target >= nums[l]) r = mid;
                    else l = mid + 1;
                }
                else r = mid;
            } else {
                if(nums[mid] > nums[l]) l = mid + 1;
                else {
                    if(target < nums[l]) l = mid + 1;
                    else r = mid;
                }
            }
        }
        return -1;
    }
};
