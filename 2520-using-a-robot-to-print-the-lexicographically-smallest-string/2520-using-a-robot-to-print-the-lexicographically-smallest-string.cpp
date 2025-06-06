class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> sufMin(n + 1);
        sufMin[n] = '{';
        for (int i = n - 1; i >= 0; --i) sufMin[i] = min(s[i], sufMin[i + 1]);
        string t, p;
        t.reserve(n);
        p.reserve(n);
        for (int i = 0; i < n; ++i) {
            t.push_back(s[i]);
            while (!t.empty() && t.back() <= sufMin[i + 1]) {
                p.push_back(t.back());
                t.pop_back();
            }
        }
        while (!t.empty()) {
            p.push_back(t.back());
            t.pop_back();
        }
        return p;
    }
};