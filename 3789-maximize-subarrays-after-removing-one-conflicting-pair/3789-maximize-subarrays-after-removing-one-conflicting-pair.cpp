class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& cp) {
        const int INF = n+1;
        vector<int> M(n+2, INF), cnt(n+2,0), sec(n+2, INF);
        for(auto &p : cp) {
            int a = p[0], b = p[1];
            if(a > b) swap(a,b);
            if(b < M[a]) { sec[a] = M[a]; M[a] = b; cnt[a] = 1; }
            else if(b == M[a]) { cnt[a]++; }
            else if(b < sec[a]) { sec[a] = b; }
        }
        vector<int> F(n+2, INF), pos(n+2,0);
        F[n] = M[n]; pos[n] = n;
        for(int i = n-1; i >= 1; i--){
            if(M[i] <= F[i+1]) { F[i] = M[i]; pos[i] = i; }
            else { F[i] = F[i+1]; pos[i] = pos[i+1]; }
        }
        F[n+1] = INF;
        long long base = 0;
        for(int i = 1; i <= n; i++){
            base += (F[i]==INF ? (long long)(n-i+1) : (long long)(F[i]-i));
        }
        vector<int> L(n+2, -1);
        for(int i = 1; i <= n; i++){
            int r = pos[i];
            if(L[r] == -1) L[r] = i;
        }
        long long best = base;
        for(int r = 1; r <= n; r++){
            if(L[r] == -1) continue;
            if(cnt[r] != 1) continue;
            int candidate = sec[r];
            int Q = min(F[r+1], candidate);
            int Lr = L[r], m = r - Lr; 
            long long sumSuffix = 0;
            if(m > 0) {
                vector<int> suf(m);
                suf[m-1] = M[r-1];
                for(int i = m-2; i >= 0; i--) {
                    suf[i] = min(M[Lr + i], suf[i+1]);
                }
                int lo = 0, hi = m;
                while(lo < hi) {
                    int mid = (lo+hi)/2;
                    if(suf[mid] >= Q) hi = mid;
                    else lo = mid+1;
                }
                int t = lo;
                for(int i = 0; i < t; i++){
                    sumSuffix += suf[i];
                }
                sumSuffix += (long long)(m - t) * Q;
            }
            long long imp = sumSuffix + Q - (long long)(m + 1) * M[r];
            best = max(best, base + imp);
        }
        return best;
    }
};
 