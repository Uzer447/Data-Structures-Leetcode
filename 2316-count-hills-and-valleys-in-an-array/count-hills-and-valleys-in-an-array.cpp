class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> a;
        a.reserve(nums.size());
        for (int x : nums) if (a.empty() || x != a.back()) a.push_back(x);
        int res = 0;
        for (int i = 1; i + 1 < (int)a.size(); ++i)
            if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
                ++res;
        return res;
    }
};