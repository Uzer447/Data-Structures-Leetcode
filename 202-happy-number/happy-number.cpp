class Solution {
public:
    int sumOfSq(int n)
    {
        int ans=0;
        while(n>0)
        {
            ans+=((n%10)*(n%10));
            n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while(st.count(n)==0)
        {
            st.insert(n);
            n=sumOfSq(n);
            //cout<<n<<endl;
            if(n==1)
                return true;
        }
        return false;
    }
};