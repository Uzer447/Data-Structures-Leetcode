#include <bits/stdc++.h>
#define rep(I, N) for (int I = 0; I < (N); ++I)
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vall(X) (X).begin(), (X).end()
#define vi vector<int>
#define vll vector<long long>
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
class Solution {
public:
    int lenOfVDiagonal(vector<vi>& g) {
        int n = g.size(), m = g[0].size();
        vector<pii> dvec = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        vector<vector<vector<vi>>> dp(4, 
            vector<vector<vi>>(2, vector<vi>(n, vi(m, 0))));
        rep(d,4) {
            int dx = dvec[d].first, dy = dvec[d].second;
            int iStart = (dx == 1 ? n - 1 : 0), iEnd = (dx == 1 ? -1 : n),
                iStep = (dx == 1 ? -1 : 1);
            int jStart = (dy == 1 ? m - 1 : 0), jEnd = (dy == 1 ? -1 : m),
                jStep = (dy == 1 ? -1 : 1);
            for (int i = iStart; i != iEnd; i += iStep)
                for (int j = jStart; j != jEnd; j += jStep)
                    for (int p = 0; p < 2; p++) {
                        int exp = (p == 0 ? 2 : 0);
                        if (g[i][j] == exp) {
                            int ni = i + dx, nj = j + dy, add = 0;
                            if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                                add = dp[d][1 - p][ni][nj];
                            dp[d][p][i][j] = 1 + add;
                        } else
                            dp[d][p][i][j] = 0;
                    }
        }
        int best = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (g[i][j] != 1)
                    continue;
                for (int d = 0; d < 4; d++) {
                    int dx = dvec[d].first, dy = dvec[d].second;
                    best = max(best, 1);
                    int dt = (d + 1) % 4;
                    int ni = i + dvec[dt].first, nj = j + dvec[dt].second;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                        best = max(best, 1 + dp[dt][0][ni][nj]);
                    int r = i, c = j, st = 0;
                    while (true) {
                        int nr = r + dx, nc = c + dy, ns = st + 1;
                        if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                            break;
                        int exp = (ns % 2 == 1 ? 2 : 0);
                        if (g[nr][nc] != exp)
                            break;
                        r = nr, c = nc, st = ns;
                        best = max(best, st + 1);
                        dt = (d + 1) % 4;
                        int rr = r + dvec[dt].first, cc = c + dvec[dt].second;
                        if (rr >= 0 && rr < n && cc >= 0 && cc < m)
                            best = max(best, st + 1 + dp[dt][st % 2][rr][cc]);
                    }
                }
            }
        return best;
    }
};