#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int, int> nummap;
    for(int i = 0; i < nums.size(); i++) {
        if(nummap.find(target - nums[i]) != nummap.end()) {
            res.push_back(i);
            res.push_back(nummap[target - nums[i]]);
            return res;
        }
        nummap[nums[i]] = i;
    }
}

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    vector<int> res = twoSum(nums, 6);
    for(int i : res){
        cout << i<<endl;
    }
}
