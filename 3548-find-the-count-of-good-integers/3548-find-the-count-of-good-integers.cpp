class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        vector<long long> fact(21, 1);
        for (int i = 1; i < 21; i++) fact[i] = fact[i - 1] * i;
        long long ans = 0;
        vector<int> curr(10, 0);
 
        function<long long(const vector<int>&)> countPerm = [&](const vector<int>& cnt) -> long long {
            long long tot = fact[n];
            for (int d = 0; d < 10; d++) tot /= fact[cnt[d]];
            if (cnt[0] > 0) {
                long long lead = fact[n - 1];
                lead /= fact[cnt[0] - 1];
                for (int d = 1; d < 10; d++) lead /= fact[cnt[d]];
                tot -= lead;
            }
            return tot;
        };
 
        function<bool(const vector<int>&)> checkPal = [&](const vector<int>& cnt) -> bool {
            int oddCount = 0, oddDigit = -1;
            for (int d = 0; d < 10; d++) {
                if (cnt[d] % 2) { oddCount++; oddDigit = d; }
            }
            if (n % 2 == 0) { if (oddCount != 0) return false; }
            else { if (oddCount != 1) return false; }
            int halfLen = n / 2;
            vector<int> half(10, 0);
            for (int d = 0; d < 10; d++) half[d] = cnt[d] / 2;
            bool found = false;
            vector<int> perm(halfLen, 0);
            function<void(int)> dfs = [&](int pos) {
                if (found) return;
                if (pos == halfLen) {
                    if (halfLen > 0 && perm[0] == 0) return;
                    string left;
                    for (int d : perm) left.push_back('0' + d);
                    string rev = left; reverse(rev.begin(), rev.end());
                    string mid = (n % 2 == 1 ? string(1, '0' + oddDigit) : "");
                    long long val = stoll(left + mid + rev);
                    if (val % k == 0) found = true;
                    return;
                }
                for (int d = 0; d < 10; d++) {
                    if (half[d] > 0) {
                        half[d]--;
                        perm[pos] = d;
                        dfs(pos + 1);
                        if (found) return;
                        half[d]++;
                    }
                }
            };
            dfs(0);
            return found;
        };
 
        function<void(int, int)> gen = [&](int digit, int rem) {
            if (digit == 10) {
                if (rem == 0) {
                    if (curr[0] == n) return;
                    long long perms = countPerm(curr);
                    if (perms == 0) return;
                    if (checkPal(curr)) ans += perms;
                }
                return;
            }
            for (int i = 0; i <= rem; i++) {
                curr[digit] = i;
                gen(digit + 1, rem - i);
            }
        };
 
        gen(0, n);
        return ans;
    }
};