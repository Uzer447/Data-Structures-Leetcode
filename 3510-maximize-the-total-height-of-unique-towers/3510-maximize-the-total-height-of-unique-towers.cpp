class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n=maximumHeight.size();
        sort(maximumHeight.begin(),maximumHeight.end(),greater<int>());
        long long sum=maximumHeight[0];
        int lastassigned=sum;
        for(int i=1;i<n;i++)
        {
            long long temp=min(maximumHeight[i],lastassigned-1);
            if(temp==0)
            return -1;
            sum+=temp;
            lastassigned=temp;
        }
        return sum;
    }
};