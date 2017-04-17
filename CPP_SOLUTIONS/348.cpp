class Solution {
public:
    vector<int> org;
    Solution(vector<int> nums) {
        org = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return org;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ret(org);
        for(int i = ret.size() - 1; i > 0; i--) {
            int id = rand() % (i + 1);
            swap(ret[i], ret[id]);
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
