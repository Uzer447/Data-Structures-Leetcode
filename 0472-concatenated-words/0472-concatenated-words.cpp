class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> wordSet;
        vector<string> res;
        sort(words.begin(), words.end(), [](const string& a, const string& b){ return a.size() < b.size();});
        for (const string& word : words) {
            if (word.empty()) continue;
            int n = word.size();
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            for (int i = 1; i <= n; ++i) {
                for (int j = max(0, i - 30); j < i; ++j) {
                    if (dp[j] && wordSet.count(word.substr(j, i - j))) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[n]) res.push_back(word);
            wordSet.insert(word);
        }
        return res;
    }
};