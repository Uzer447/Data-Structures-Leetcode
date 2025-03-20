#include <bits/stdc++.h>
using namespace std;
class DinnerPlates {
public:
    int cap;
    vector<vector<int>> stacks;
    priority_queue<int, vector<int>, greater<int>> avail;
    int right;
    DinnerPlates(int capacity) : cap(capacity), right(-1) {}
    void push(int val) {
        while (!avail.empty() && avail.top() < stacks.size() && stacks[avail.top()].size() == cap)
            avail.pop();
        int idx;
        if (!avail.empty() && avail.top() < stacks.size())
            idx = avail.top();
        else {
            idx = stacks.size();
            stacks.push_back({});
        }
        stacks[idx].push_back(val);
        if (stacks[idx].size() < cap)
            avail.push(idx);
        right = max(right, idx);
    }
    int pop() {
        while (right >= 0 && (right >= stacks.size() || stacks[right].empty()))
            right--;
        if (right < 0)
            return -1;
        int val = stacks[right].back();
        stacks[right].pop_back();
        avail.push(right);
        return val;
    }
    int popAtStack(int index) {
        if (index >= stacks.size() || stacks[index].empty())
            return -1;
        int val = stacks[index].back();
        stacks[index].pop_back();
        avail.push(index);
        if (index == right && stacks[index].empty())
            while (right >= 0 && (right >= stacks.size() || stacks[right].empty()))
                right--;
        return val;
    }
};