#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        vector<bool> used(n, false);
        function<void(int, int)> dfs = [&](int cnt, int last) {
            if(cnt == n) {
                ans++;
                return;
            }
            for(int i = 0; i < n; i++){
                if(used[i]) continue;
                if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
                if(cnt == 0 || isPerfectSquare(nums[i] + last)){
                    used[i] = true;
                    dfs(cnt + 1, nums[i]);
                    used[i] = false;
                }
            }
        };
        dfs(0, 0);
        return ans;
    }
private:
    bool isPerfectSquare(int x) {
        int r = (int)sqrt(x);
        return r * r == x;
    }
};