class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        int l=0,r=0,maxn=0,mine=INT_MAX;
        long long cnt=0;
        while(r<n)
        {
            mp[nums[r]]++;
            maxn=mp.rbegin()->first;
            mine=mp.begin()->first;
            while(maxn-mine>2)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                mp.erase(nums[l]);
                l++;
                maxn=mp.rbegin()->first;
                mine=mp.begin()->first;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
};