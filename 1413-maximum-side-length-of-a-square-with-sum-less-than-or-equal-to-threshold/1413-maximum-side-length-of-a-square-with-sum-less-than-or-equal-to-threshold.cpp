class Solution {
public:
    bool isPossible(int k, vector<vector<int>>& mat, int limit) {
        int sum = 0, n = mat.size(), m = mat[0].size();
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = 0; j < m; j++) {
                sum += mat[i][j];
                v[i][j] = sum;
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (i > 0)
                    v[i][j] += v[i - 1][j];
            }
        }
        for (int i = k - 1; i < n; i++) {
            for (int j = k - 1; j < m; j++) {
                int upper_sq = (i - k >= 0) ? v[i - k][j] : 0;
                int left_sq = (j - k >= 0) ? v[i][j - k] : 0;
                int upper_left_sq =
                    (i - k >= 0 && j - k >= 0) ? v[i - k][j - k] : 0;
                int curr_sum = v[i][j] - upper_sq - left_sq +
                               upper_left_sq;
                if (curr_sum <= limit) return true;
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size(), ans = 0;
        int i = 1, j = min(n, m);
        while (i <= j) {
            int mid = (i + j) / 2;
            if (isPossible(mid, mat, threshold)) {
                ans = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return ans;
    }
};