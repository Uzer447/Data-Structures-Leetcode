class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long> pq;
        for(auto it:gifts)
        {
            pq.push(it);
        }
        while(k--)
        {
            long long x=pq.top();
            pq.pop();
            long long temp=sqrt(x);
            pq.push(temp);
        }
        long long ans=0;
        while(!pq.empty())
        {
            ans=ans+pq.top();
            pq.pop();
        }
        return ans;
    }
};