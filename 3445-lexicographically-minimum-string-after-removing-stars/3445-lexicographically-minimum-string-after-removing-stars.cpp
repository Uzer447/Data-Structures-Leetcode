class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<int> pos[26];
        vector<char> del(n, 0);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                int c = 0;
                while (c < 26 && pos[c].empty()) ++c;
                int j = pos[c].back();
                pos[c].pop_back();
                del[j] = 1;
                del[i] = 1;
            } else {
                pos[s[i] - 'a'].push_back(i);
            }
        }
        string res;
        res.reserve(n);
        for (int i = 0; i < n; ++i)
            if (!del[i] && s[i] != '*') res.push_back(s[i]);
        return res;
    }
};