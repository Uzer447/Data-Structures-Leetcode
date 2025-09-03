class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        vector<long long> xs, ys;
        xs.reserve(n);
        ys.reserve(n);
        for (auto& p : points) {
            xs.push_back(p[0]);
            ys.push_back(p[1]);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        int X = xs.size(), Y = ys.size();
        unordered_map<long long, int> mx, my;
        mx.reserve(X * 2);
        my.reserve(Y * 2);
        for (int i = 0; i < X; ++i) mx[xs[i]] = i + 1;
        for (int i = 0; i < Y; ++i) my[ys[i]] = i + 1;
        vector<vector<int>> pref(X + 1, vector<int>(Y + 1));
        for (auto& p : points) ++pref[mx[p[0]]][my[p[1]]];
        for (int i = 1; i <= X; ++i) {
            int row = 0;
            for (int j = 1; j <= Y; ++j) {
                row += pref[i][j];
                pref[i][j] = pref[i - 1][j] + row;
            }
        }
        auto rect = [&](int lx, int rx, int ly, int ry) {
            return pref[rx][ry] - pref[lx - 1][ry] - pref[rx][ly - 1] + pref[lx - 1][ly - 1];
        };
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long xA = points[i][0], yA = points[i][1];
            int cxA = mx[xA], cyA = my[yA];
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                long long xB = points[j][0], yB = points[j][1];
                if (xA <= xB && yA >= yB) {
                    int cxB = mx[xB], cyB = my[yB];
                    if (rect(cxA, cxB, cyB, cyA) == 2) ++ans;
                }
            }
        }
        return (int)ans;
    }
};