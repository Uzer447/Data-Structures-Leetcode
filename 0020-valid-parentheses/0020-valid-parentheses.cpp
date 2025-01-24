#include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool ans=true;
        if(s[0]==']' || s[0]==')' || s[0]=='}')
            ans=false;
        else
        {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[' || s[i]=='(' || s[i]=='{')
            st.push(s[i]);
            else
            {
                if(!st.empty())
                {
            if(s[i]==')' && st.top()!='(')
                ans= false;
            else if(s[i]==')' && st.top()=='(')
                st.pop();
            else if(s[i]==']' && st.top()!='[')
                ans=false;
            else if(s[i]==']' && st.top()=='[') 
                    st.pop();
            else if(s[i]=='}' && st.top()!='{')
                ans= false;
            else if(s[i]=='}' && st.top()=='{')
                st.pop();
            }
                else 
                    ans=false;
            }
        }
        }
        if(!st.empty())
            ans=false;
        return ans;
        
    }
};