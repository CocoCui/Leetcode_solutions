class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> count_down;
        unordered_map<int, int> count_up, count;
        int maxlen = 0;
        for(int i: nums) {
            if(count[i] > 0) continue;
            count[i] ++;
            int l = count_down[i - 1];
            int r = count_up[i + 1];
            //cout << i << " " << l << " " << r << endl;
            count_up[i - l] = l + r + 1;
            count_down[i + r] = l + r + 1;
            maxlen = max(maxlen, l + r + 1);
        }
        return maxlen;
    }
};
