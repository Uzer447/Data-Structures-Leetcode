class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mpp;
        int n=s.size();
        int l=0;
        int r=0;
        int ans=0;
        while(r<n)
        {
            while(mpp[s[r]]>0)
            {
                mpp[s[l]]--;
                l++;
            }
            mpp[s[r]]++;
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};