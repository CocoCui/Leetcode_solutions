class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        for(int i = 0; i < gas.size(); i++) {
            gas[i] -= cost[i];
            sum += gas[i];
        }
        if(sum < 0) return -1;
        int remain = 0, begin = 0;
        for(int i = 0; i < gas.size() * 2 + 1; i++) {
            if(remain + gas[i % gas.size()] < 0) {
                remain = 0;
                begin = i + 1;
            } else {
                remain += gas[i % gas.size()];
                if(i == begin + gas.size()) return begin;
            }
        }
        return -1;
    }
}
