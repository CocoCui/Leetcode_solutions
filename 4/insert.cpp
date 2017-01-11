#include <iostream>
#include <vector>
using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m1 = (nums1.size() + nums2.size() - 1) / 2, m2 = (nums1.size() + nums2.size() ) / 2;
    vector<double> midnum;
    int l1 = 0, l2 = 0, p = 0, end = 0, curnum = 0;
    double ans = 0;
    if(l1 == nums1.size()) end = 1;
    if(l2 == nums2.size()) end = 2;
    while(l1 < nums1.size() || l2 < nums2.size()) {
        if(end == 1) {
            curnum = nums2[l2];
            l2 ++;
        }
        else if(end == 2) {
            curnum = nums1[l1];
            l1 ++;
        }
        else {
            if(nums1[l1] < nums2[l2]) {
                curnum = nums1[l1];
                l1 ++;
            }
            else {
                curnum = nums2[l2];
                l2 ++;
            }
            if(l1 == nums1.size()) end = 1;
            if(l2 == nums2.size()) end = 2;
        }
        if(p == m1 || p == m2) {
            midnum.push_back(curnum);
        }
        p++;
    }
    for(int i = 0; i < midnum.size(); i++) {
        ans += midnum[i];
    }
    ans /= midnum.size();
    return ans;
}

int main() {

}
