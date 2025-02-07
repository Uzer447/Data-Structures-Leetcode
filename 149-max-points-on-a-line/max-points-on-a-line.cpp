class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        if(n <= 2) return n;
        for(int i = 0; i < n; ++i) {
            map<pair<int, int>, int> m;
            int maxp = 0;
            for(int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                if(dx == 0) {
                    // Vertical line
                    dy = 1;
                    dx = 0;
                } else if(dy == 0) {
                    // Horizontal line
                    dy = 0;
                    dx = 1;
                } else {
                    int g = gcd(dx, dy);
                    dx /= g;
                    dy /= g;
                    if(dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                }
                m[{dy, dx}]++;
                maxp = max(maxp, m[{dy, dx}]);
            }
            res = max(res, maxp + 1);
        }
        return res;
    }
private:
    int gcd(int a, int b) {
        return b == 0 ? abs(a) : gcd(b, a % b);
    }
};