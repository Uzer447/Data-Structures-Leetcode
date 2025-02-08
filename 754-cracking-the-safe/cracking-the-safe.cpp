class Solution {
public:
    string crackSafe(int n, int k) {
        string res;
        unordered_set<string> visited;
        string node(n - 1, '0');
        dfs(node, k, visited, res);
        res += node;
        reverse(res.begin(), res.end());
        return res;
    }
private:
    void dfs(string node, int k, unordered_set<string>& visited, string& res) {
        for (int i = 0; i < k; ++i) {
            string next = node + to_string(i);
            if (!visited.count(next)) {
                visited.insert(next);
                dfs(next.substr(1), k, visited, res);
                res += to_string(i);
            }
        }
    }
};