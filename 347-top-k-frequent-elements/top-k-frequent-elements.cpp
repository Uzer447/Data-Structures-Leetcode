class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k==nums.size())
        return nums;
        unordered_map<int,int> mp;
        for(auto it:nums)
        {
            mp[it]++;
        }   
        auto comp = [&mp](int n1, int n2) { return mp[n1] > mp[n2]; };
        priority_queue<int,vector<int>,decltype(comp)> pq(comp);
        for(auto it:mp)
        {
            pq.push(it.first);
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans(k);
        for(int i=0;i<k;i++)
        {
            ans[k-1-i]=pq.top();
            pq.pop();
        }
        return ans;

    }
};