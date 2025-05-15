class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int last = -1;
        for (int i = 0; i < (int)words.size(); ++i) {
            if (last == -1 || groups[i] != last) {
                res.push_back(words[i]);
                last = groups[i];
            }
        }
        return res;
    }
};