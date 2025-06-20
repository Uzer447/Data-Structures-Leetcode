class Solution {
public:
    int maxDistance(string s, int k) {
        auto solve = [&](int a, int b) {
            int used = 0, sum = 0, best = 0;
            for (char c : s) {
                int dx = 0, dy = 0;
                switch (c) {
                    case 'N': dy = 1; break;
                    case 'S': dy = -1; break;
                    case 'E': dx = 1; break;
                    case 'W': dx = -1; break;
                }
                int d = a * dx + b * dy;
                if (d != 1 && used < k) {
                    d = 1;
                    ++used;
                }
                sum += d;
                if (sum > best) best = sum;
            }
            return best;
        };
        int ans = 0;
        int opt[4][2] = { {1,1}, {1,-1}, {-1,1}, {-1,-1} };
        for (auto &p : opt) ans = max(ans, solve(p[0], p[1]));
        return ans;
    }
};