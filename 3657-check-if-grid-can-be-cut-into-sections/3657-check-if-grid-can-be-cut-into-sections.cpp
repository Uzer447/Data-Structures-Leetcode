#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int m = rectangles.size();
        vector<int> xs, xe, ys, ye;
        for(auto &r : rectangles){
            xs.push_back(r[0]); ys.push_back(r[1]);
            xe.push_back(r[2]); ye.push_back(r[3]);
        }
        sort(xs.begin(), xs.end());
        sort(xe.begin(), xe.end());
        sort(ys.begin(), ys.end());
        sort(ye.begin(), ye.end());
        auto solve = [&](int n, int m, const vector<int>& s, const vector<int>& e) -> bool {
            vector<int> v;
            for(auto x : s) if(x > 0 && x < n) v.push_back(x);
            for(auto x : e) if(x > 0 && x < n) v.push_back(x);
            sort(v.begin(), v.end());
            v.erase(unique(v.begin(), v.end()), v.end());
            vector<array<int, 3>> cand;
            for(auto pos : v) {
                int cntS = lower_bound(s.begin(), s.end(), pos) - s.begin();
                int cntE = upper_bound(e.begin(), e.end(), pos) - e.begin();
                if(cntS != cntE) continue;
                int lower = cntE;
                int upper = m - (lower_bound(s.begin(), s.end(), pos) - s.begin());
                cand.push_back({pos, lower, upper});
            }
            int sz = cand.size();
            for (int i = 0; i < sz; i++){
                if(cand[i][1] < 1) continue;
                int need = m - 1 - cand[i][1];
                if(need < 1) continue;
                int lo = i + 1, hi = sz - 1, idx = -1;
                while(lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if(cand[mid][2] <= need) { idx = mid; hi = mid - 1; }
                    else lo = mid + 1;
                }
                if(idx != -1 && cand[idx][2] >= 1) return true;
            }
            return false;
        };
        if(solve(n, m, ys, ye)) return true;
        if(solve(n, m, xs, xe)) return true;
        return false;
    }
};