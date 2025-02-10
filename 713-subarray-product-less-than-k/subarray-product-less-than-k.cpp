class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k<=1) return 0;
        int l=0,r=0;
        int prod=1;
        int cnt=0;
        while(r<n){
            prod*=nums[r];
            while(prod>=k){
                prod=prod/nums[l];
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
};