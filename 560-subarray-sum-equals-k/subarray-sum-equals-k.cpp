class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        int presum=0;
        int cnt=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            presum+=nums[i];
            int rem=presum-k;
            cnt+=mp[rem];
            mp[presum]+=1;
        }
        return cnt;
    }
};