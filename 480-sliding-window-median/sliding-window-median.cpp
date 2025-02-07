class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> lo, hi;
        vector<double> res;
        for(int i = 0; i < nums.size(); ++i) {
            if(lo.empty() || nums[i] <= *lo.rbegin()) lo.insert(nums[i]);
            else hi.insert(nums[i]);
            if(lo.size() > hi.size() + 1) {
                hi.insert(*lo.rbegin());
                lo.erase(prev(lo.end()));
            } else if(hi.size() > lo.size()) {
                lo.insert(*hi.begin());
                hi.erase(hi.begin());
            }
            if(i >= k) {
                if(lo.find(nums[i - k]) != lo.end()) lo.erase(lo.find(nums[i - k]));
                else hi.erase(hi.find(nums[i - k]));
                if(lo.size() > hi.size() + 1) {
                    hi.insert(*lo.rbegin());
                    lo.erase(prev(lo.end()));
                } else if(hi.size() > lo.size()) {
                    lo.insert(*hi.begin());
                    hi.erase(hi.begin());
                }
            }
            if(i >= k - 1) {
                if(k % 2) res.push_back(*lo.rbegin());
                else res.push_back(((double)*lo.rbegin() + *hi.begin()) / 2.0);
            }
        }
        return res;
    }
};