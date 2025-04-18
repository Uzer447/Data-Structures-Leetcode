class Solution {
public:
    string countAndSay(int n) {
        if (n==1){
            return "1";
        }
        string s=countAndSay(n-1);
        string res="";
        int count=1;
        res+=s[0];
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                count++;
            }
            else{
                res.insert(res.end()-1,1,char(count+48));
                res+=s[i+1];
                count=1;
            }
        }
        res.insert(res.end()-1,1,char(count+48));  
        return res;
    }
};