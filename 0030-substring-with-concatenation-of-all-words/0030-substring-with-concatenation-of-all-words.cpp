#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) return {};
        int wordLen = words[0].size(), totalLen = wordLen * words.size(), n = s.size();
        unordered_map<string, int> wordId;
        int id = 0;
        for (string& word : words) if (!wordId.count(word)) wordId[word] = id++;
        vector<int> wordCount(id), res;
        for (string& word : words) wordCount[wordId[word]]++;
        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i;
            vector<int> currCount(id);
            while (right + wordLen <= n) {
                string w = s.substr(right, wordLen);
                right += wordLen;
                if (wordId.count(w)) {
                    int idx = wordId[w];
                    currCount[idx]++;
                    while (currCount[idx] > wordCount[idx]) {
                        string lw = s.substr(left, wordLen);
                        currCount[wordId[lw]]--;
                        left += wordLen;
                    }
                    if (right - left == totalLen) res.push_back(left);
                } else {
                    currCount.assign(id, 0);
                    left = right;
                }
            }
        }
        return res;
    }
};