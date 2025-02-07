class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        int i = 0;
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExp = false;
        bool digitAfterExp = true;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            i++;
        }

        for (; i < n; i++) {
            char c = s[i];
            if (isdigit(c)) {
                seenDigit = true;
                if (seenExp) {
                    digitAfterExp = true;
                }
            } else if (c == '.') {
                if (seenDot || seenExp) {
                    return false;
                }
                seenDot = true;
            } else if (c == 'e' || c == 'E') {
                if (seenExp || !seenDigit) {
                    return false;
                }
                seenExp = true;
                digitAfterExp = false;
            } else if (c == '+' || c == '-') {
                if (s[i - 1] == 'e' || s[i - 1] == 'E') {
                    continue;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        return seenDigit && digitAfterExp;
    }
};