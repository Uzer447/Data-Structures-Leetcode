#include <bits/stdc++.h>
using namespace std;
class FreqStack {
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> group;
    int maxfreq;
public:
    FreqStack() {
        maxfreq = 0;
    }
    void push(int val) {
        int f = ++freq[val];
        if(f > maxfreq) maxfreq = f;
        group[f].push_back(val);
    }
    int pop() {
        int x = group[maxfreq].back();
        group[maxfreq].pop_back();
        freq[x]--;
        if(group[maxfreq].empty()) maxfreq--;
        return x;
    }
};