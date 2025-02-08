class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int card : cards) nums.push_back(card);
        return solve(nums);
    }
private:
    const double EPSILON = 1e-6;
    bool solve(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) return fabs(nums[0] - 24) < EPSILON;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                vector<double> nextNums;
                for (int k = 0; k < n; ++k)
                    if (k != i && k != j) nextNums.push_back(nums[k]);
                double a = nums[i], b = nums[j];
                vector<double> results = {a + b, a - b, b - a, a * b};
                if (fabs(b) > EPSILON) results.push_back(a / b);
                if (fabs(a) > EPSILON) results.push_back(b / a);
                for (double res : results) {
                    nextNums.push_back(res);
                    if (solve(nextNums)) return true;
                    nextNums.pop_back();
                }
            }
        }
        return false;
    }
};