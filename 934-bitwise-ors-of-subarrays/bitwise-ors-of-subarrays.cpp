class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, cur;
        for (int x : arr) {
            unordered_set<int> nxt = {x};
            for (int v : cur) nxt.insert(v | x);
            cur.swap(nxt);
            res.insert(cur.begin(), cur.end());
        }
        return res.size();
    }
};