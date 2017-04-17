class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        int jump = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            jump --;
            //cout << jump << endl;
            if(jump < 0) return 0;
            jump = max(jump, nums[i]);
        }
        return 1;
    }
};
