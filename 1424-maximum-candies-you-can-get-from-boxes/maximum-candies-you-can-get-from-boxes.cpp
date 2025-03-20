#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size(), ans = 0;
        vector<bool> opened(n, false), waiting(n, false), haveKey(n, false);
        queue<int> q;
        for (int box : initialBoxes) {
            if (status[box] == 1) q.push(box);
            else waiting[box] = true;
        }
        while (!q.empty()) {
            int box = q.front();
            q.pop();
            if (opened[box]) continue;
            opened[box] = true;
            ans += candies[box];
            for (int k : keys[box]) {
                if (!haveKey[k]) {
                    haveKey[k] = true;
                    if (waiting[k]) {
                        q.push(k);
                        waiting[k] = false;
                    }
                }
            }
            for (int nb : containedBoxes[box]) {
                if (!opened[nb]) {
                    if (status[nb] == 1 || haveKey[nb]) q.push(nb);
                    else waiting[nb] = true;
                }
            }
        }
        return ans;
    }
};