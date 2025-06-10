class Solution {
public:
    int helper(string s) {
        vector<int> freq(26, 0);
        for (auto c : s)
            freq[c - 'a']++;
        vector<int> odd, even;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                if (freq[i] % 2 == 1)
                    odd.push_back(freq[i]);
                else
                    even.push_back(freq[i]);
            }
        }
        int maxans = INT_MIN;
        for (auto o : odd) {
            for (auto e : even) {
                maxans=max(maxans,o - e);
            }
        }
        return maxans;
    }
    int maxDifference(string s) {
        return helper(s);
    }
};