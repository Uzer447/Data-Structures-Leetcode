#include <vector>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> avail(26, 0);
        for (char c : letters)
            avail[c - 'a']++;
        int n = words.size();
        vector<vector<int>> wordCount(n, vector<int>(26, 0));
        vector<int> wordScore(n, 0);
        for (int i = 0; i < n; i++) {
            for (char c : words[i]) {
                wordCount[i][c - 'a']++;
                wordScore[i] += score[c - 'a'];
            }
        }
        function<int(int, vector<int>&)> dfs = [&](int i, vector<int>& cur) -> int {
            if (i == n) return 0;
            int res = dfs(i + 1, cur);
            bool possible = true;
            for (int j = 0; j < 26; j++) {
                if (wordCount[i][j] > cur[j]) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                for (int j = 0; j < 26; j++)
                    cur[j] -= wordCount[i][j];
                res = max(res, wordScore[i] + dfs(i + 1, cur));
                for (int j = 0; j < 26; j++)
                    cur[j] += wordCount[i][j];
            }
            return res;
        };
        return dfs(0, avail);
    }
};