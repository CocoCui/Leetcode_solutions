class Solution {
public:
    vector<vector<int>> res;
    void dfs(int l, vector<int>& nums) {
        if(l == nums.size()) {
            res.push_back(nums);
        }
        for(int i = l; i < nums.size(); i++) {
            swap(nums[i], nums[l]);
            dfs(l + 1, nums);
            swap(nums[i], nums[l]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        dfs(0, nums);
        return res;
    }
};
