class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int cnt[100] = {};
        int res = 0;
        for (auto& d : dominoes) {
            int a = d[0], b = d[1];
            if (a > b) swap(a, b);
            int key = a * 10 + b;
            res += cnt[key]++;
        }
        return res;
    }
};