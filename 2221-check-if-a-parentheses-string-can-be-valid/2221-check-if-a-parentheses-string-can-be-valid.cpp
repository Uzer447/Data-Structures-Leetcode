class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2) return false;
        int min_bal = 0, max_bal = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    ++min_bal;
                    ++max_bal;
                } else {
                    --min_bal;
                    --max_bal;
                }
            } else {
                --min_bal;
                ++max_bal;
            }
            if (max_bal < 0) return false;
            min_bal = max(min_bal, 0);
        }
        return min_bal == 0;
    }
};