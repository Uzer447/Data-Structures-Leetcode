class Solution {
    string lower(const string& s) {
        string t=s;
        for(char& c:t) c=tolower(c);
        return t;
    }
    string devowel(const string& s) {
        string t=s;
        for(char& c:t){
            c=tolower(c);
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') c='*';
        }
        return t;
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(),wordlist.end());
        unordered_map<string,string> cap,vow;
        for(const string& w:wordlist){
            string lw=lower(w);
            cap.emplace(lw,w);
            string vw=devowel(w);
            vow.emplace(vw,w);
        }
        vector<string> res;
        for(const string& q:queries){
            if(exact.count(q)){res.push_back(q);continue;}
            string lq=lower(q);
            auto it=cap.find(lq);
            if(it!=cap.end()){res.push_back(it->second);continue;}
            string vq=devowel(q);
            auto it2=vow.find(vq);
            if(it2!=vow.end()){res.push_back(it2->second);continue;}
            res.push_back("");
        }
        return res;
    }
};