#include <bits/stdc++.h>
#define rep(I, N) for (int I = 0; I < (N); ++I)
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define vall(X) (X).begin(), (X).end()
#define vi vector<int>
#define vll vector<long long>
using namespace std;
const int MOD = 1e9 + 7;
const int SIZE = 1e6 + 10;
class Solution {
public:
    bool helper(string s, int n) {
        while (s.size() > 2) {
            string ans;
            rep(i,s.size()-1) {
                ans.push_back(((s[i] - '0' + s[i + 1] - '0') % 10) + '0');
            }
            s = ans;
        }
        if(s[0] == s[1]) return true;
        return false;
    }
    bool hasSameDigits(string s) {
        return helper(s,s.size());
    }
};