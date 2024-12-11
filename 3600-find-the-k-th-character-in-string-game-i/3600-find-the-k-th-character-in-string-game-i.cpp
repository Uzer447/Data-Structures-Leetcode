class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<500)
        {
            int n=s.size();
            for(int i=0;i<n;i++)
            {
                s=s+(char)(s[i]+1);
                if(s.size()>=500)
                break;
            }
        }
        return s[k-1];
    }
};