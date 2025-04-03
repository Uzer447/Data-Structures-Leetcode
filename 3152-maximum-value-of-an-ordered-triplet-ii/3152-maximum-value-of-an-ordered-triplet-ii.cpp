#include <vector>
#include <algorithm>
using namespace std;
 
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<long long> L(n), R(n);
        L[0] = nums[0];
        for(int i = 1; i < n; i++) L[i] = max(L[i-1], (long long)nums[i-1]);
        R[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) R[i] = max((long long)nums[i], R[i+1]);
        long long ans = 0;
        for(int j = 1; j <= n-2; j++) {
            long long diff = L[j] - nums[j];
            if(diff > 0) ans = max(ans, diff * R[j+1]);
        }
        return ans;
    }
};