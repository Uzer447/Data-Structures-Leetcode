class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            if(!st.empty())
                pse[i]=st.top();
            st.push(i);
        }
        stack<int> stk;
        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty() && arr[stk.top()]>arr[i]) stk.pop();
            if(!stk.empty()) nse[i]=stk.top();
            stk.push(i);
        }
        long long sum=0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            sum+=(1LL*(i-pse[i])*1LL*(nse[i]-i)*1LL*arr[i])%mod;
            sum%=mod;
        }
        return sum;
    }
};