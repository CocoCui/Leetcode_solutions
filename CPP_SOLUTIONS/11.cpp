class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxwater = 0;
        while(l < r) {
            int mh = min(height[l], height[r]);
            maxwater = max(maxwater, (r - l) * mh);
            if(mh == height[l]) {
                while(l < r && height[l] <= mh) l++;
            } else {
                while(l < r && height[r] <= mh) r--;
            }
        }
        return maxwater;
        
    }
};
