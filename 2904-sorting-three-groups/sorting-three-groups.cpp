class Solution {
public:
    int minOps(int i, int j, vector<int>& nums) {
        int count = 0;
        for(int x=0;x<i;x++) {
            if(nums[x] != 1) count++;
        // if the value at x is not 1, an operation is needed!
        }
        for(int x=i;x<j;x++) {
            if(nums[x] != 2) count++;
        // if the value at x is not 2, an operation is needed!
        }
        for(int x=j;x<nums.size();x++) {
            if(nums[x] != 3) count++;
        // if the value at x is not 3, an operation is needed!
        }
        return count;
    }
    int minimumOperations(vector<int>& nums) {
        int out = INT_MAX;
        int n = nums.size();
        for(int i=0;i<=n;i++) {
            for(int j=i;j<=n;j++) {
                out = min(out, minOps(i, j, nums));
            }
        }
        return out;
    }
};
// Please consider upvoting if the solution helped! Thank you :)