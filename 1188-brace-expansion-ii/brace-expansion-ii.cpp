#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> res = parse(expression, i);
        return vector<string>(res.begin(), res.end());
    }
    set<string> parse(string &s, int &i) {
        set<string> cur; cur.insert("");
        set<string> ans;
        while(i < s.size() && s[i] != '}'){
            set<string> part;
            if(s[i] == '{'){
                i++;
                part = parse(s, i);
            } else {
                part.insert(string(1, s[i]));
                i++;
            }
            set<string> tmp;
            for(auto &a : cur)
                for(auto &b : part)
                    tmp.insert(a + b);
            cur = tmp;
            if(i < s.size() && s[i] == ','){
                for(auto &str : cur) ans.insert(str);
                cur.clear(); cur.insert("");
                i++;
            }
        }
        for(auto &str : cur) ans.insert(str);
        if(i < s.size() && s[i] == '}') i++;
        return ans;
    }
};