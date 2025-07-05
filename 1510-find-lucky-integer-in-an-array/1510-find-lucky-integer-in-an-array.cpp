class Solution {
public:
    int findLucky(vector<int>& arr) {
        int cnt[501] = {};
        for (int x : arr) ++cnt[x];
        for (int v = 500; v >= 1; --v) if (cnt[v] == v) return v;
        return -1;
    }
};