class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            int xa = points[i][0], ya = points[i][1];
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int xb = points[j][0], yb = points[j][1];
                if (!(xa <= xb && ya >= yb) || (xa == xb && ya == yb)) continue;
                bool ok = true;
                for (int k = 0; k < n && ok; ++k) {
                    if (k == i || k == j) continue;
                    int xk = points[k][0], yk = points[k][1];
                    if (xa <= xk && xk <= xb && yb <= yk && yk <= ya) ok = false;
                }
                if (ok) ++ans;
            }
        }
        return ans;
    }
};