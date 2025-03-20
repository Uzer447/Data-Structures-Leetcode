#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int newGroup = m;
        for (int i = 0; i < n; i++)
            if (group[i] == -1)
                group[i] = newGroup++;
        vector<vector<int>> groupItems(newGroup);
        for (int i = 0; i < n; i++)
            groupItems[group[i]].push_back(i);
        vector<vector<int>> groupGraph(newGroup);
        vector<int> groupIndegree(newGroup, 0);
        for (int i = 0; i < n; i++)
            for (int pre : beforeItems[i])
                if (group[pre] != group[i]) {
                    groupGraph[group[pre]].push_back(group[i]);
                    groupIndegree[group[i]]++;
                }
        queue<int> qu;
        vector<int> groupOrder;
        for (int i = 0; i < newGroup; i++)
            if (groupIndegree[i] == 0)
                qu.push(i);
        while (!qu.empty()) {
            int cur = qu.front();
            qu.pop();
            groupOrder.push_back(cur);
            for (int nxt : groupGraph[cur])
                if (--groupIndegree[nxt] == 0)
                    qu.push(nxt);
        }
        if (groupOrder.size() != newGroup)
            return {};
        vector<int> res;
        for (int grp : groupOrder) {
            vector<int>& items = groupItems[grp];
            int sz = items.size();
            if (sz == 0)
                continue;
            unordered_map<int, int> pos;
            for (int i = 0; i < sz; i++)
                pos[items[i]] = i;
            vector<vector<int>> localAdj(sz);
            vector<int> localIndegree(sz, 0);
            for (int i = 0; i < sz; i++) {
                int item = items[i];
                for (int pre : beforeItems[item])
                    if (group[pre] == grp) {
                        localAdj[pos[pre]].push_back(i);
                        localIndegree[i]++;
                    }
            }
            queue<int> q;
            vector<int> localOrder;
            for (int i = 0; i < sz; i++)
                if (localIndegree[i] == 0)
                    q.push(i);
            while (!q.empty()) {
                int cur = q.front();
                q.pop();
                localOrder.push_back(items[cur]);
                for (int nxt : localAdj[cur])
                    if (--localIndegree[nxt] == 0)
                        q.push(nxt);
            }
            if (localOrder.size() != sz)
                return {};
            for (int it : localOrder)
                res.push_back(it);
        }
        return res;
    }
};