class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        if (firstPlayer > secondPlayer) swap(firstPlayer, secondPlayer);
        unordered_map<int, pair<int,int>> dp;
        function<pair<int,int>(int,int,int)> dfs = [&](int players,int a,int b)->pair<int,int>{
            if (a > b) swap(a,b);
            int key = (players<<10)|(a<<5)|b;
            if (dp.count(key)) return dp[key];
            if (a + b == players + 1) return dp[key]={1,1};
            set<tuple<int,int,int>> nxt;
            vector<pair<int,int>> pairs;
            for (int i=1;i<=players/2;++i) pairs.push_back({i,players+1-i});
            int mid = players&1 ? (players+1)>>1 : -1;
            vector<int> start;
            if (mid!=-1) start.push_back(mid);
            function<void(int,vector<int>&)> back = [&](int idx,vector<int>& cur){
                if (idx==(int)pairs.size()){
                    vector<int> ord=cur;
                    sort(ord.begin(),ord.end());
                    int sz=ord.size(),pa=-1,pb=-1;
                    for (int i=0;i<sz;++i){
                        if (ord[i]==a) pa=i+1;
                        if (ord[i]==b) pb=i+1;
                    }
                    if (pa==-1||pb==-1) return;
                    if (pa>pb) swap(pa,pb);
                    nxt.emplace(sz,pa,pb);
                    return;
                }
                int u=pairs[idx].first,v=pairs[idx].second;
                if (u==a||u==b||v==a||v==b){
                    int w=(u==a||u==b)?u:v;
                    cur.push_back(w);
                    back(idx+1,cur);
                    cur.pop_back();
                }else{
                    cur.push_back(u);
                    back(idx+1,cur);
                    cur.pop_back();
                    cur.push_back(v);
                    back(idx+1,cur);
                    cur.pop_back();
                }
            };
            back(0,start);
            int mn=1e9,mx=0;
            for (auto [np,na,nb]:nxt){
                auto res=dfs(np,na,nb);
                mn=min(mn,res.first);
                mx=max(mx,res.second);
            }
            return dp[key]={mn+1,mx+1};
        };
        auto ans=dfs(n,firstPlayer,secondPlayer);
        return {ans.first,ans.second};
    }
};