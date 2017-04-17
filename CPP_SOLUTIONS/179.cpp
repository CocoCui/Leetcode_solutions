//179. Largest Number

bool cmp(int& a, int& b) {
    if(a == b) return 0;
    string an = to_string(a);
    string bn = to_string(b);
    string before = an + bn, after = bn + an;
    return before > after;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res = "";
        if(nums[0] == 0) return "0";
        for(int n: nums) {
            res += to_string(n);
        }
        return res;
    }
};
