#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num), a = s, b = s;

        for (char &c : a) {
            if (c != '9') {
                char t = c;
                for (char &d : a) if (d == t) d = '9';
                break;
            }
        }

        if (b[0] != '1') {
            char t = b[0];
            for (char &d : b) if (d == t) d = '1';
        } else {
            int idx = -1;
            for (int i = 1; i < (int)b.size(); ++i)
                if (b[i] != '0' && b[i] != '1') { idx = i; break; }
            if (idx != -1) {
                char t = b[idx];
                for (char &d : b) if (d == t) d = '0';
            }
        }

        long long A = stoll(a), B = stoll(b);
        return int(A - B);
    }
};