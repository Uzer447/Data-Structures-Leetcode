class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        vector<int> pos(n),val(n);
        for(int i=0;i<n;i++){
            pos[i]=fruits[i][0];
            val[i]=fruits[i][1];
        }
        vector<long long> pref(n+1,0);
        for(int i=0;i<n;i++) pref[i+1]=pref[i]+val[i];
        long long ans=0;
        int l=0;
        for(int r=0;r<n;r++){
            while(l<=r){
                long long L=pos[l],R=pos[r],dist;
                if(startPos<=L) dist=R-startPos;
                else if(startPos>=R) dist=startPos-L;
                else{
                    long long left=startPos-L,right=R-startPos;
                    dist=min(2*left+right,2*right+left);
                }
                if(dist<=k) break;
                ++l;
            }
            ans=max(ans,pref[r+1]-pref[l]);
        }
        return (int)ans;
    }
};