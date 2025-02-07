class Solution {
public:
    int calculate(string s) {
        int n = s.size(), total = 0, sign = 1, num = 0;
        vector<pair<int, int>> stack;
        int prev_token = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                prev_token = 1;
            } else if (c == '+' || c == '-') {
                total += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                else {
                    if (prev_token == 1 || prev_token == 2) sign = -1;
                    else sign *= -1;
                }
                prev_token = 0;
            } else if (c == '(') {
                stack.push_back({total, sign});
                total = 0;
                sign = 1;
                prev_token = 0;
            } else if (c == ')') {
                total += sign * num;
                num = 0;
                auto [last_total, last_sign] = stack.back();
                stack.pop_back();
                total = last_total + last_sign * total;
                prev_token = 2;
            }
        }
        total += sign * num;
        return total;
    }
};