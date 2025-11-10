class Solution {
public:
    int minOperations(vector<int>& nums) {
        long long ans = 0;
        vector<int> st;
        st.reserve(nums.size());
        for (int x : nums) {
            if (x == 0) {
                ans += st.size();
                st.clear();
            } else {
                while (!st.empty() && st.back() > x) {
                    st.pop_back();
                    ++ans;
                }
                if (st.empty() || st.back() < x) st.push_back(x);
            }
        }
        ans += st.size();
        return (int)ans;
    }
};