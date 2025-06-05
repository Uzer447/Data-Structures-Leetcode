#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> p(26);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) { return p[x] == x ? x : p[x] = find(p[x]); };
        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) return;
            if (a < b) p[b] = a;
            else p[a] = b;
        };
        for (int i = 0; i < s1.size(); ++i) unite(s1[i] - 'a', s2[i] - 'a');
        string res;
        res.reserve(baseStr.size());
        for (char c : baseStr) res.push_back(char(find(c - 'a') + 'a'));
        return res;
    }
};