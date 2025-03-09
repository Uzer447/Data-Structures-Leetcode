class Solution {
public:
    bool isalternating(vector<int> &v,int l,int r)
    {
        for(int i=l;i<r;i++)
        {
            if(v[i]==v[i+1])
            {
                return false;
            }
        }
        return true;
    }
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        colors.insert(colors.end(),colors.begin(),colors.begin()+k-1);
        // for(auto it:colors)
        // cout<<it<<" ";
        // cout<<endl;
        int ans=0;
        int n=colors.size();
        int len=1;
        int maxlen=1;
        for(int i=1;i<n;i++)
        {
            if(colors[i-1]!=colors[i])
            {
                len++;
            }
            else
            {
                ans+=max(0,len-k+1);
                len=1;
            }
        }
        ans+=max(0,len-k+1);
        return max(0,ans);
    }
};