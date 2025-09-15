class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool bad[26] = {};
        for (char c : brokenLetters) bad[c - 'a'] = true;
        int ans = 0;
        bool ok = true;
        for (int i = 0; i <= (int)text.size(); ++i) {
            if (i == (int)text.size() || text[i] == ' ') {
                if (ok) ++ans;
                ok = true;
            } else if (bad[text[i] - 'a']) ok = false;
        }
        return ans;
    }
};