#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> idx;
    RandomizedCollection() {}
    bool insert(int val) {
        nums.push_back(val);
        idx[val].insert(nums.size()-1);
        return idx[val].size()==1;
    }
    bool remove(int val) {
        if(!idx.count(val)||idx[val].empty()) return false;
        int i=*idx[val].begin();
        idx[val].erase(i);
        int last=nums.back();
        nums[i]=last;
        idx[last].insert(i);
        idx[last].erase(nums.size()-1);
        nums.pop_back();
        if(idx[val].empty()) idx.erase(val);
        return true;
    }
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};