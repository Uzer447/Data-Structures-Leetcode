class Solution {
    int par[26];
    int find(int x){ return par[x]==x?x:par[x]=find(par[x]); }
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return;
        if(a<b) par[b]=a;
        else par[a]=b;
    }
public:
    string smallestEquivalentString(string s1,string s2,string baseStr){
        iota(begin(par),end(par),0);
        for(int i=0;i<s1.size();++i) unite(s1[i]-'a',s2[i]-'a');
        string ans; ans.reserve(baseStr.size());
        for(char c:baseStr) ans.push_back(char(find(c-'a')+'a'));
        return ans;
    }
};