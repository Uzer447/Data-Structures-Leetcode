class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<long long,long long> cnt;
        cnt.reserve(nums.size()*2);
        cnt.max_load_factor(0.7);
        cnt[0]=1;
        long long pref=0, ans=0;
        for(int x:nums){
            if(x%modulo==k) ++pref;
            long long cur=pref%modulo;
            long long need=(cur-k)%modulo;
            if(need<0) need+=modulo;
            auto it=cnt.find(need);
            if(it!=cnt.end()) ans+=it->second;
            ++cnt[cur];
        }
        return ans;
    }
};