class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        nums.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) == mp.end()) {
            mp[val] = nums.size();
            nums.push_back(val);
            return 1;
        }
        return 0;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) != mp.end()) {
            int val_idx = mp[val];
            int last = nums.back();
            nums[val_idx] = last;
            mp[last] = val_idx;
            nums.pop_back();
            mp.erase(val);
            return 1;
        }
        return 0;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
    unordered_map<int, int> mp;
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
