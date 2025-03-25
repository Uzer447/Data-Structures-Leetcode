#include <bits/stdc++.h>
using namespace std;

struct Candidate {
    int pos, lower, upper;
};

bool solveDim(int n, int m, const vector<int>& starts,
              const vector<int>& ends) {
    vector<int> cand;
    for (auto s : starts)
        if (s > 0 && s < n)
            cand.push_back(s);
    for (auto e : ends)
        if (e > 0 && e < n)
            cand.push_back(e);
    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());
    vector<Candidate> valid;
    for (auto pos : cand) {
        int cntS = (int)(lower_bound(starts.begin(), starts.end(), pos) -
                         starts.begin());
        int cntE =
            (int)(upper_bound(ends.begin(), ends.end(), pos) - ends.begin());
        if (cntS != cntE)
            continue;
        Candidate c;
        c.pos = pos;
        c.lower = cntE;
        c.upper = m - (int)(lower_bound(starts.begin(), starts.end(), pos) -
                            starts.begin());
        valid.push_back(c);
    }
    int sz = valid.size();
    if (sz < 2)
        return false;
    for (int i = 0; i < sz - 1; i++) {
        if (valid[i].lower < 1)
            continue;
        int thresh = m - 1 - valid[i].lower;
        if (thresh < 1)
            continue;
        int l = i + 1, r = sz - 1, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (valid[mid].upper <= thresh) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (ans != -1 && valid[ans].upper >= 1)
            return true;
    }
    return false;
}

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int m = rectangles.size();
        vector<int> xStarts, xEnds, yStarts, yEnds;
        for (auto& r : rectangles) {
            xStarts.push_back(r[0]);
            yStarts.push_back(r[1]);
            xEnds.push_back(r[2]);
            yEnds.push_back(r[3]);
        }
        sort(xStarts.begin(), xStarts.end());
        sort(xEnds.begin(), xEnds.end());
        sort(yStarts.begin(), yStarts.end());
        sort(yEnds.begin(), yEnds.end());
        if (solveDim(n, m, yStarts, yEnds))
            return true;
        if (solveDim(n, m, xStarts, xEnds))
            return true;
        return false;
    }
};