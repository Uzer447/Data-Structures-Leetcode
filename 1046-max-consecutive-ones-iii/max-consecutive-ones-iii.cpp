class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0,maxlen=0,zeroes=0;
        while(r<n)
        {
            if(nums[r]==0)zeroes++;
            if(zeroes>k)
            {
                if(nums[l]==0)
                zeroes--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};