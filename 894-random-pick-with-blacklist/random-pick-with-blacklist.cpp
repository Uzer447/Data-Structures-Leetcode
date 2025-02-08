#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int M;
    unordered_map<int, int> mp;
    mt19937 rng{random_device{}()};
    Solution(int n, vector<int>& blacklist) {
        M = n - blacklist.size();
        unordered_set<int> black(blacklist.begin(), blacklist.end());
        int w = M;
        for (int b : blacklist) {
            if (b < M) {
                while (black.count(w)) w++;
                mp[b] = w++;
            }
        }
    }
    int pick() {
        int k = uniform_int_distribution<int>(0, M - 1)(rng);
        return mp.count(k) ? mp[k] : k;
    }
};