class Solution {
public:
    static bool compareByFreq(const pair<int, int>& a,
                              const pair<int, int>& b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> freq(mp.begin(), mp.end());
        sort(freq.begin(), freq.end(), compareByFreq);

        vector<int> result;
        for (const auto& i : freq) {
            if (k > 0) {
                result.push_back(i.first);
                k--;
            }
        }
        return result;
    }
};