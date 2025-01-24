class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(), i = 0;
        while (i < n && s[i] == ' ') i++;
        if (i == n) return 0;
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '-') sign = -1;
            i++;
        }
        while (i < n && s[i] == '0') i++;
        long res = 0;
        int digitsRead = 0;
        while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i++] - '0');
            digitsRead++;
            if (sign * res >= INT_MAX) return INT_MAX;
            if (sign * res <= INT_MIN) return INT_MIN;
        }
        if (digitsRead == 0) return 0;
        res *= sign;
        if (res >= INT_MAX) return INT_MAX;
        if (res <= INT_MIN) return INT_MIN;
        return res;
    }
};