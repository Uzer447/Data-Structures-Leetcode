class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long> pq;
        for(auto it:nums)
        pq.push(1LL*it);
        long long score=0;
        while(k--)
        {
            int x=pq.top();
            score+=x;
            pq.pop();
            int temp=x/3;
            if(x%3!=0)
            temp++;
            pq.push(temp);
        }
        return score;
    }
};