class Solution {
public:
    vector<vector<int>> res;
    vector<int> row;
    void dfs(int idx, vector<int>& nums) {
        if(idx == nums.size()) {
            res.push_back(row);
            return;
        }
        row.push_back(nums[idx]);
        dfs(idx + 1, nums);
        int l = idx, r = nums.size();
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] <= row.back()) l = mid + 1;
            else r = mid;
        }
        idx = l;
        row.pop_back();
        dfs(idx, nums);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return res;
    }
};
