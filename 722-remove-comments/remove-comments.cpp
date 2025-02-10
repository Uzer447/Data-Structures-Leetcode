class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
       vector<string> ans;
       string temp = "";
       bool flag = false;
       for(auto &s: source){
           for(int i = 0;i<s.length();i++){
               if(!flag && i<s.length()-1 && s[i] == '/' && s[i+1] == '/'){
                   break;
               }
               if(!flag && i<s.length()-1 && s[i]=='/' && s[i+1]=='*'){
                   flag = true;
                   i++;
                   continue;
               }
               if(flag && i<s.length()-1 && s[i]=='*' && s[i+1]=='/'){
                   flag = false;
                   i++;
                   continue;
               }
               if(!flag){
                   temp.push_back(s[i]);
               }
           }
           if(!temp.empty() && !flag){
               ans.push_back(temp);
               temp = "";
           }
       }
       return ans;
    }
};    