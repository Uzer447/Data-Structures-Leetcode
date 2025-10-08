class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> res;
        for (int s : spells) {
            long long need = (success + s - 1) / (long long)s;
            auto it = lower_bound(potions.begin(), potions.end(), need);
            res.push_back(m - (it - potions.begin()));
        }
        return res;
    }
};