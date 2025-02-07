class Solution {
public:
    vector<string> res;
    unordered_map<string, multiset<string>> g;
    void dfs(string u) {
        while (g[u].size()) {
            auto it = g[u].begin();
            string v = *it;
            g[u].erase(it);
            dfs(v);
        }
        res.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& t : tickets) g[t[0]].insert(t[1]);
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};