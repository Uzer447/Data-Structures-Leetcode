class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res;
        int n = part.size();
        for (char c : s) {
            res.push_back(c);
            if (res.size() >= n && res.substr(res.size() - n, n) == part) {
                res.resize(res.size() - n);
            }
        }
        return res;
    }
};