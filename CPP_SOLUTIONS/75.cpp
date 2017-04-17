class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> col(3, 0);
        for(int i: nums) col[i] ++;
        nums.clear();;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < col[i]; j++) {
                nums.push_back(i);
            }
        return;
    }
};
