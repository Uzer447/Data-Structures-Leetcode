#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size(), lo = 1, hi = n, start = -1, len = 0;
        auto search = [&](int L) -> int {
            unsigned long long h = 0, aL = 1;
            for (int i = 0; i < L; i++){
                h = h * 26ULL + (s[i] - 'a');
                aL *= 26ULL;
            }
            unordered_map<unsigned long long, int> seen;
            seen[h] = 0;
            for (int i = 1; i <= n - L; i++){
                h = h * 26ULL - (s[i-1] - 'a') * aL + (s[i+L-1] - 'a');
                if(seen.find(h) != seen.end()){
                    int j = seen[h];
                    if(s.compare(j, L, s, i, L)==0)
                        return i;
                }
                seen[h] = i;
            }
            return -1;
        };
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            int idx = search(mid);
            if(idx != -1){
                start = idx;
                len = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return start == -1 ? "" : s.substr(start, len);
    }
};