class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist(n, -1);
        int cur = node1, step = 0;
        while (cur != -1 && dist[cur] == -1) {
            dist[cur] = step++;
            cur = edges[cur];
        }
        vector<char> seen(n, 0);
        cur = node2; step = 0;
        int ans = -1, best = INT_MAX;
        while (cur != -1 && !seen[cur]) {
            seen[cur] = 1;
            if (dist[cur] != -1) {
                int val = max(dist[cur], step);
                if (val < best || (val == best && cur < ans)) {
                    best = val;
                    ans = cur;
                }
            }
            cur = edges[cur];
            ++step;
        }
        return ans;
    }
};