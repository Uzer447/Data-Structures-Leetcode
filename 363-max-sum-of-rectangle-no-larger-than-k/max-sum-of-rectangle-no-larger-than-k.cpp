class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
        for (int left = 0; left < n; ++left) {
            vector<int> sums(m);
            for (int right = left; right < n; ++right) {
                for (int i = 0; i < m; ++i) sums[i] += matrix[i][right];
                set<int> s{0};
                int currSum = 0, currMax = INT_MIN;
                for (int sum : sums) {
                    currSum += sum;
                    auto it = s.lower_bound(currSum - k);
                    if (it != s.end()) currMax = max(currMax, currSum - *it);
                    s.insert(currSum);
                }
                res = max(res, currMax);
                if (res == k) return k;
            }
        }
        return res;
    }
};