#include <bits/stdc++.h>
using namespace std;
 
bool isPal(const string &s) {
    int i = 0, j = s.size()-1;
    while(i < j) {
        if(s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}
 
class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        long long L = stoll(left), R = stoll(right);
        long long rSqrt = floor(sqrt((long double)R));
        int ans = 0;
        for (int i = 1; i < 100000; i++) {
            string s = to_string(i);
            string rev = s; reverse(rev.begin(), rev.end());
            string oddStr = s + (rev.size() > 0 ? rev.substr(1) : "");
            long long oddRoot = stoll(oddStr);
            // If both odd and even palindrome roots are greater than rSqrt, further iterations will exceed R
            string evenStr = s + rev;
            long long evenRoot = stoll(evenStr);
            if(oddRoot > rSqrt && evenRoot > rSqrt)
                break;
            if(oddRoot <= rSqrt) {
                long long sq = oddRoot * oddRoot;
                if(sq >= L && sq <= R && isPal(to_string(sq)))
                    ans++;
            }
            if(evenRoot <= rSqrt) {
                long long sq = evenRoot * evenRoot;
                if(sq >= L && sq <= R && isPal(to_string(sq)))
                    ans++;
            }
        }
        return ans;
    }
};
