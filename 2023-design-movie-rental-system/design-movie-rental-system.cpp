class MovieRentingSystem {
    using ll = long long;
    static ll key(int s,int m){ return ( (ll)s<<20 ) | m; }
    unordered_map<ll,int> cost;
    unordered_map<int,set<pair<int,int>>> freeList;         
    set<tuple<int,int,int>> busy;                            
public:
    MovieRentingSystem(int n, vector<vector<int>>& e){
        for(auto &v:e){
            int s=v[0],m=v[1],p=v[2];
            cost[key(s,m)]=p;
            freeList[m].insert({p,s});
        }
    }
    vector<int> search(int movie){
        vector<int> ans;
        auto it=freeList.find(movie);
        if(it==freeList.end()) return ans;
        for(auto &pr:it->second){
            ans.push_back(pr.second);
            if(ans.size()==5) break;
        }
        return ans;
    }
    void rent(int shop,int movie){
        int p=cost[key(shop,movie)];
        freeList[movie].erase({p,shop});
        busy.insert({p,shop,movie});
    }
    void drop(int shop,int movie){
        int p=cost[key(shop,movie)];
        busy.erase({p,shop,movie});
        freeList[movie].insert({p,shop});
    }
    vector<vector<int>> report(){
        vector<vector<int>> res;
        for(auto &t:busy){
            res.push_back({get<1>(t),get<2>(t)});
            if(res.size()==5) break;
        }
        return res;
    }
};