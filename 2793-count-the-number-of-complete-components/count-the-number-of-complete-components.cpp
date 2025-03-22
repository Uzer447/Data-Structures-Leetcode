class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph(n);
        for(auto &e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> comp;
                stack<int> st;
                st.push(i);
                visited[i] = true;
                while (!st.empty()) {
                    int cur = st.top();
                    st.pop();
                    comp.push_back(cur);
                    for (auto nb : graph[cur])
                        if (!visited[nb]) {
                            visited[nb] = true;
                            st.push(nb);
                        }
                }
                int k = comp.size();
                long long edgeCount = 0;
                unordered_set<int> compSet(comp.begin(), comp.end());
                for (auto node : comp) {
                    for (auto nb : graph[node])
                        if (compSet.count(nb))
                            edgeCount++;
                }
                edgeCount /= 2;
                if (edgeCount == (long long)k * (k - 1) / 2)
                    ans++;
            }
        }
        return ans;
    }
};