class Solution {
public:
    bool isPallindrome(string s)
    {
        string t=s;
        reverse(s.begin(),s.end());
        return (t==s);
    }
    void func(int ind,vector<string> &curr,vector<vector<string>> &ans,string s,int n)
    {   
        if(ind==n)
        {
            ans.push_back(curr);
            return;
        }
        string temp="";
        for(int i=ind;i<n;i++)
        {
            temp=temp+s[i];
            if(isPallindrome(temp))
            {
                curr.push_back(temp);
                func(i+1,curr,ans,s,n);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> ans;
        int n=s.size();
        func(0,curr,ans,s,n);
        return ans;
    }
};