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
    bool canFinish(ll T,vector<int> &ranks,int cars) {
            ll total = 0;
            for (auto r : ranks) {
                total += (ll)floor(sqrt((long double)T / r));
                if (total >= cars)
                    return true;
            }
            return total >= cars;
        };
    long long repairCars(vector<int>& ranks, int cars) {
        int minRank = *min_element(vall(ranks));
        ll lo = 0, hi = (ll)minRank * cars * cars;
        while (lo < hi) {
            ll mid = lo + (hi-lo)/2;
            if (canFinish(mid,ranks,cars))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};