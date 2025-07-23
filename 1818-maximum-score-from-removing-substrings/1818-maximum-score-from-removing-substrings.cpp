class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char f1,f2,s1,s2; int v1,v2;
        if(x>=y){f1='a';f2='b';v1=x;s1='b';s2='a';v2=y;}
        else{f1='b';f2='a';v1=y;s1='a';s2='b';v2=x;}
        auto sweep=[&](const string& str,char a,char b,int val,long long& sc){
            string st; st.reserve(str.size());
            for(char c:str){
                st.push_back(c);
                int n=st.size();
                if(n>=2&&st[n-2]==a&&st[n-1]==b){st.pop_back();st.pop_back();sc+=val;}
            }
            return st;
        };
        long long ans=0;
        string rem=sweep(s,f1,f2,v1,ans);
        sweep(rem,s1,s2,v2,ans);
        return (int)ans;
    }
};