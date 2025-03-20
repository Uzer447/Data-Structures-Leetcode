#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        for (int r1 = 0; r1 < m; r1++) {
            vector<int> colSum(n, 0);
            for (int r2 = r1; r2 < m; r2++) {
                for (int j = 0; j < n; j++)
                    colSum[j] += matrix[r2][j];
                int prefix = 0;
                unordered_map<int, int> cnt;
                cnt[0] = 1;
                for (int k = 0; k < n; k++) {
                    prefix += colSum[k];
                    ans += cnt[prefix - target];
                    cnt[prefix]++;
                }
            }
        }
        return ans;
    }
};