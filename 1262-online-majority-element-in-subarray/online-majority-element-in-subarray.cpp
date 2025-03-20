#include <bits/stdc++.h>
using namespace std;
 
class MajorityChecker {
    int n;
    vector<int> a;
    vector<vector<int>> pos;
    vector<pair<int,int>> seg;
    pair<int,int> mergePair(pair<int,int> p, pair<int,int> q) {
        if(p.first == -1) return q;
        if(q.first == -1) return p;
        if(p.first == q.first) return {p.first, p.second + q.second};
        return p.second > q.second ? pair<int,int>{p.first, p.second - q.second} : p.second < q.second ? pair<int,int>{q.first, q.second - p.second} : pair<int,int>{-1, 0};
    }
    void build(int idx, int l, int r) {
        if(l == r) {
            seg[idx] = {a[l], 1};
            return;
        }
        int m = (l + r) / 2;
        build(idx * 2 + 1, l, m);
        build(idx * 2 + 2, m + 1, r);
        seg[idx] = mergePair(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }
    pair<int,int> queryTree(int idx, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) return seg[idx];
        if(r < ql || l > qr) return {-1, 0};
        int m = (l + r) / 2;
        return mergePair(queryTree(idx * 2 + 1, l, m, ql, qr), queryTree(idx * 2 + 2, m + 1, r, ql, qr));
    }
public:
    MajorityChecker(vector<int>& arr) {
        a = arr;
        n = a.size();
        pos.resize(20001);
        for(int i = 0; i < n; i++) pos[a[i]].push_back(i);
        seg.resize(4 * n);
        build(0, 0, n - 1);
    }
    int query(int left, int right, int threshold) {
        pair<int,int> cand = queryTree(0, 0, n - 1, left, right);
        if(cand.first == -1) return -1;
        int x = cand.first;
        int cnt = upper_bound(pos[x].begin(), pos[x].end(), right) - lower_bound(pos[x].begin(), pos[x].end(), left);
        return cnt >= threshold ? x : -1;
    }
};