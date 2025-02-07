class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if (numerator == 0)
            return "0";
        string ans;
        if ((numerator < 0 && denominator > 0) ||
            (numerator > 0 && denominator < 0))
            ans += "-";
        if (numerator < 0)
            numerator *= -1;
        if (denominator < 0)
            denominator *= -1;
        long long quotient = numerator / denominator;
        long long remainder = numerator % denominator;
        ans += to_string(quotient);
        if (remainder == 0)
            return ans;
        ans += '.';
        unordered_map<int, int> mp;
        while (remainder != 0) {
            if (mp.find(remainder) != mp.end()) {
                int pos = mp[remainder];
                ans.insert(pos, "(");
                ans += ")";
                break;
            } else {
                mp[remainder] = ans.size();
                remainder *= 10;
                quotient = remainder / denominator;
                remainder %= denominator;
                ans += to_string(quotient);
            }
        }
        return ans;
    }
};