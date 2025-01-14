class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        return dfs(s, 0, wordSet, memo);
    }
private:
    vector<string> dfs(string& s, int start, unordered_set<string>& wordSet, unordered_map<int, vector<string>>& memo) {
        if (memo.count(start)) return memo[start];
        vector<string> sentences;
        if (start == s.size()) {
            sentences.push_back("");
            return sentences;
        }
        for (int end = start + 1; end <= s.size(); ++end) {
            string word = s.substr(start, end - start);
            if (wordSet.count(word)) {
                vector<string> subsentences = dfs(s, end, wordSet, memo);
                for (string& subsentence : subsentences) {
                    sentences.push_back(word + (subsentence.empty() ? "" : " " + subsentence));
                }
            }
        }
        memo[start] = sentences;
        return sentences;
    }
};