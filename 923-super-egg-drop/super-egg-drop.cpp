#include <vector>
using namespace std;
 
class Solution {
public:
    int superEggDrop(int k, int n) {
        int m = 0;
        vector<int> dp(k + 1, 0);
        while (dp[k] < n) {
            m++;
            for (int j = k; j > 0; j--) {
                dp[j] = dp[j] + dp[j - 1] + 1;
            }
        }
        return m;
    }
};