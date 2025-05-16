
class Solution {
    struct Node{int dp, grp, idx;};
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size(), bestEnd = 0;
        vector<int> dp(n,1), pre(n,-1);
        
        unordered_map<string,array<Node,2>> mp;         
        auto upd=[&](array<Node,2>& a,const Node& cur){
            if (cur.dp<=a[0].dp){
                if (cur.grp!=a[0].grp && cur.dp>a[1].dp) a[1]=cur;
            }else{
                if (cur.grp==a[0].grp){a[0]=cur;}
                else{a[1]=a[0];a[0]=cur;}
            }
        };
        
        for(int i=0;i<n;++i){
            int g=groups[i], bestDp=0, bestIdx=-1;
            const string& w=words[i];
            int L=w.size();
            string pat=w;
            for(int p=0;p<L;++p){
                char old=pat[p]; pat[p]='#';
                auto it=mp.find(pat);
                if(it!=mp.end()){
                    for(int t=0;t<2;++t){
                        const Node& nd=it->second[t];
                        if(nd.dp && nd.grp!=g && nd.dp>bestDp){
                            bestDp=nd.dp; bestIdx=nd.idx;
                        }
                    }
                }
                pat[p]=old;
            }
            dp[i]=bestDp+1; pre[i]=bestIdx;
            
            Node cur{dp[i],g,i};
            for(int p=0;p<L;++p){
                char old=pat[p]; pat[p]='#';
                auto &arr=mp[pat];
                upd(arr,cur);
                pat[p]=old;
            }
            if(dp[i]>dp[bestEnd]) bestEnd=i;
        }
        
        vector<string> res;
        for(int x=bestEnd;x!=-1;x=pre[x]) res.push_back(words[x]);
        reverse(res.begin(),res.end());
        return res;
    }
};