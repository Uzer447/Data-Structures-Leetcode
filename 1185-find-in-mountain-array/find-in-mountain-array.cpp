#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(mountainArr.get(m) < mountainArr.get(m + 1)) l = m + 1;
            else r = m;
        }
        int peak = l;
        int idx = bsearch(mountainArr, target, 0, peak, true);
        if(idx != -1) return idx;
        return bsearch(mountainArr, target, peak + 1, n - 1, false);
    }
    
    int bsearch(MountainArray &mountainArr, int target, int l, int r, bool asc) {
        while(l <= r) {
            int m = l + (r - l) / 2;
            int val = mountainArr.get(m);
            if(val == target) return m;
            if(asc) {
                if(val < target) l = m + 1;
                else r = m - 1;
            } else {
                if(val < target) r = m - 1;
                else l = m + 1;
            }
        }
        return -1;
    }
};