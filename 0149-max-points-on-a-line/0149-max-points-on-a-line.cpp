class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        if (n <= 2) return n;
        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> cnt;
            int dup = 1, max_cnt = 0;
            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0], dy = points[j][1] - points[i][1];
                if (dx == 0 && dy == 0) {
                    ++dup;
                } else {
                    int g = gcd(dx, dy);
                    dx /= g;
                    dy /= g;
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                    if (dx == 0 && dy < 0) {
                        dy = -dy;
                    }
                    ++cnt[{dy, dx}];
                    max_cnt = max(max_cnt, cnt[{dy, dx}]);
                }
            }
            res = max(res, max_cnt + dup);
        }
        return res;
    }
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};