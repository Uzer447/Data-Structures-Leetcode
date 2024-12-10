class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(auto it:nums)
        {
            int temp=0;
            while(it>0)
            {
                temp=temp+it%10;
                it/=10;
            }
            ans=min(ans,temp);
        }
        return ans;
    }
};