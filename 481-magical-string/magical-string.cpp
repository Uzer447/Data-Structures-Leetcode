class Solution {
public:
    int magicalString(int n) {
        if (n <= 3) return 1;

        string s = "122";
        int i = 2;
        while (s.size() < n) {
            int len = s[i] - '0'; 
            char next_char = (s.back() == '1') ? '2' : '1';

            s.append(len, next_char);
            i++;
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++cnt;
            }
        }

        return cnt;
    }
};