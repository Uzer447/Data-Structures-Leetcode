#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k == 1) return 0;
        vector<long long> diffs;
        diffs.reserve(n - 1);
        for (int i = 0; i < n - 1; i++) {
            diffs.push_back((long long)weights[i] + weights[i+1]);
        }
        sort(diffs.begin(), diffs.end());
        int cuts = k - 1;
        long long minExtra = 0, maxExtra = 0;
        for (int i = 0; i < cuts; i++) minExtra += diffs[i];
        for (int i = n - 2; i >= n - 1 - cuts; i--) maxExtra += diffs[i];
        return maxExtra - minExtra;
    }
};