class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int cnt[10] = {};
        for (int d : digits) ++cnt[d];
        vector<int> res;
        for (int num = 100; num < 1000; num += 2) {
            int a = num / 100, b = (num / 10) % 10, c = num % 10;
            if (!cnt[a] || !cnt[b] || !cnt[c]) continue;
            if (a == b && b == c) { if (cnt[a] < 3) continue; }
            else if (a == b)      { if (cnt[a] < 2) continue; }
            else if (a == c)      { if (cnt[a] < 2) continue; }
            else if (b == c)      { if (cnt[b] < 2) continue; }
            res.push_back(num);
        }
        return res;
    }
};