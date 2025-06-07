class Solution {
public:
    string clearStars(string s) {
        int n = s.size(), cur = 0;
        vector<int> pos[26];
        vector<char> del(n);
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (ch == '*') {
                while (cur < 26 && pos[cur].empty()) ++cur;
                int j = pos[cur].back();
                pos[cur].pop_back();
                del[j] = del[i] = 1;
                if (pos[cur].empty()) ++cur;
            } else {
                int c = ch - 'a';
                pos[c].push_back(i);
                if (c < cur) cur = c;
            }
        }
        string res;
        res.reserve(n);
        for (int i = 0; i < n; ++i)
            if (!del[i] && s[i] != '*') res.push_back(s[i]);
        return res;
    }
};