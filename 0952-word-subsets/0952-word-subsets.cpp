class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0);
        for (const string& b : words2) {
            vector<int> freq(26, 0);
            for (char c : b) freq[c - 'a']++;
            for (int i = 0; i < 26; ++i) maxFreq[i] = max(maxFreq[i], freq[i]);
        }
        vector<string> result;
        for (const string& a : words1) {
            vector<int> freq(26, 0);
            for (char c : a) freq[c - 'a']++;
            int i = 0;
            for (; i < 26; ++i) if (freq[i] < maxFreq[i]) break;
            if (i == 26) result.push_back(a);
        }
        return result;
    }
};