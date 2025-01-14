class Solution {
public:
    int calculate(string s) {
        int n = s.size(), result = 0, sign = 1, num = 0, i = 0;
        vector<pair<int, int>> stk;
        auto is_unary_minus = [&](int idx) {
            int j = idx -1;
            while (j >= 0 && s[j] == ' ') --j;
            if (j < 0 || s[j] == '(') return true;
            return false;
        };
        while (i < n) {
            if (s[i] == ' ') {
                ++i;
            } else if (isdigit(s[i])) {
                num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
            } else if (s[i] == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
                ++i;
            } else if (s[i] == '-') {
                result += sign * num;
                num = 0;
                if (is_unary_minus(i)) {
                    sign *= -1;
                } else {
                    sign = -1;
                }
                ++i;
            } else if (s[i] == '(') {
                stk.push_back({result, sign});
                result = 0;
                sign = 1;
                ++i;
            } else if (s[i] == ')') {
                result += sign * num;
                num = 0;
                auto [prev_res, prev_sign] = stk.back(); stk.pop_back();
                result = prev_res + prev_sign * result;
                ++i;
            } else {
                ++i;
            }
        }
        result += sign * num;
        return result;
    }
};