#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        int L = s.size(), k = digits.size();
        long long cnt = 0;
        auto ipow = [&](int a, int b) {
            long long res = 1;
            while(b--) res *= a;
            return res;
        };
        for(int i = 1; i < L; i++) cnt += ipow(k, i);
        for(int i = 0; i < L; i++){
            int smaller = 0;
            for(auto &d : digits) {
                if(d[0] < s[i]) smaller++;
            }
            cnt += smaller * ipow(k, L - i - 1);
            bool found = false;
            for(auto &d : digits) {
                if(d[0] == s[i]) {found = true; break; }
            }
            if(!found) return cnt;
            if(i == L - 1) cnt++;
        }
        return cnt;
    }
};