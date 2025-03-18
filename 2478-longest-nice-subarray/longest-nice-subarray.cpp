class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,maxlen=0;
        int mask=0;
        while(r<n)
        {
            while((mask & nums[r])!=0)
            {
                mask^=nums[l];
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            mask|=nums[r];
            r++;
        }
        return maxlen;
    }
};