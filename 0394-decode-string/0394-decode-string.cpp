class Solution {
public:
    string helper(string& s, int& i) {
        int x = 0;
        while (s[i] != '[') {
            x = x * 10 + s[i] - '0';
            i++;
        }
        i++;
        string rs;
        while (s[i] != ']') {
            if (s[i] >= '0' && s[i] <= '9') {
                rs += helper(s, i);
            } else {
                rs += s[i];
            }
            i++;
        }
        string ans;
        while (x--) {
            ans += rs;
        }
        return ans;
    }

    string decodeString(string s) {
        int i = 0;
        string ans;
        while (i < s.size()) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans += helper(s, i);
            } else {
                ans += s[i];
            }
            i++;
        }
        return ans;
    }
};