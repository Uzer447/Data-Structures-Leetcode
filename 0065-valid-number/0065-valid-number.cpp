class Solution {
public:
    bool isNumber(string s) {
        int n = s.length(), i = 0;
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;
        bool isNumeric = false, isDot = false, isExp = false;
        while (i < n && isdigit(s[i])) { i++; isNumeric = true; }
        if (i < n && s[i] == '.') {
            i++; isDot = true;
            while (i < n && isdigit(s[i])) { i++; isNumeric = true; }
        }
        if (!isNumeric) return false;
        if (i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++; isExp = true;
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;
            bool isExpNum = false;
            while (i < n && isdigit(s[i])) { i++; isExpNum = true; }
            if (!isExpNum) return false;
        }
        return i == n;
    }
};