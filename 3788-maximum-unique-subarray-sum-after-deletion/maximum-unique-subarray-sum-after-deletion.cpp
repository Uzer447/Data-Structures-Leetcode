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
    int helper(vector<int>& nums, int n) {
        int ans = 0;
        unordered_set<int> st;
        bool flag = false;
        rep(i, n) {
            if (nums[i] > 0) {
                flag = true;
                if (st.count(nums[i]) == 0) {
                    ans += nums[i];
                    st.insert(nums[i]);
                }
            }
        }
        if (flag == true)
            return ans;
        return *max_element(vall(nums));
    }
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        return helper(nums, n);
    }
};