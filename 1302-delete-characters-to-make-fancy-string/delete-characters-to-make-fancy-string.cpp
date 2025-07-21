class Solution {
public:
    string makeFancyString(string s) {
        string res;
        res.reserve(s.size());              

        for (char c : s) {
            int m = res.size();
            if (m >= 2 && res[m - 1] == c && res[m - 2] == c) {
                continue;                    
            }
            res.push_back(c);
        }
        return res;
    }
};