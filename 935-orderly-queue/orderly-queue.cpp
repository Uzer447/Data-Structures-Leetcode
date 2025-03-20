#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            string res = s;
            int n = s.size();
            for(int i = 1; i < n; i++){
                string cur = s.substr(i) + s.substr(0, i);
                if(cur < res) res = cur;
            }
            return res;
        }
        sort(s.begin(), s.end());
        return s;
    }
};