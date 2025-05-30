class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> g1(n), g2(m);
        for (auto& e : edges1) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }
        vector<int> col1(n, -1), col2(m, -1);
        long long cnt1[2] = {0, 0}, cnt2[2] = {0, 0};
        stack<int> st;
        st.push(0);
        col1[0] = 0;
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            ++cnt1[col1[u]];
            for (int v : g1[u])
                if (col1[v] == -1) {
                    col1[v] = col1[u] ^ 1;
                    st.push(v);
                }
        }
        st.push(0);
        col2[0] = 0;
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            ++cnt2[col2[u]];
            for (int v : g2[u])
                if (col2[v] == -1) {
                    col2[v] = col2[u] ^ 1;
                    st.push(v);
                }
        }
        long long best = max(cnt2[0], cnt2[1]);
        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
            ans[i] = int((col1[i] == 0 ? cnt1[0] : cnt1[1]) + best);
        return ans;
    }
};