class Solution {
    vector<vector<int>> g;
    vector<int> par,sub,tin,tout;
    int timer;
    void dfs(int u,int p,const vector<int>& a){
        par[u]=p;
        tin[u]=++timer;
        int x=a[u];
        for(int v:g[u]){
            if(v==p) continue;
            dfs(v,u,a);
            x^=sub[v];
        }
        sub[u]=x;
        tout[u]=++timer;
    }
    bool anc(int u,int v){                 // u is ancestor of v ?
        return tin[u]<=tin[v]&&tout[v]<=tout[u];
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        g.assign(n,{});
        for(auto&e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        par.assign(n,-1);
        sub.assign(n,0);
        tin.assign(n,0);
        tout.assign(n,0);
        timer=0;
        dfs(0,-1,nums);
        int tot=sub[0];

        vector<int> child;
        child.reserve(edges.size());
        for(auto&e:edges){
            int u=e[0],v=e[1];
            child.push_back(par[u]==v?u:v);
        }

        int m=child.size(),ans=INT_MAX;
        for(int i=0;i<m;i++){
            int c1=child[i];
            for(int j=i+1;j<m;j++){
                int c2=child[j],x1,x2,x3;
                if(anc(c1,c2)){
                    x1=sub[c2];
                    x2=sub[c1]^x1;
                    x3=tot^sub[c1];
                }else if(anc(c2,c1)){
                    x1=sub[c1];
                    x2=sub[c2]^x1;
                    x3=tot^sub[c2];
                }else{
                    x1=sub[c1];
                    x2=sub[c2];
                    x3=tot^x1^x2;
                }
                int mx=max(x1,max(x2,x3));
                int mn=min(x1,min(x2,x3));
                ans=min(ans,mx-mn);
            }
        }
        return ans;
    }
};