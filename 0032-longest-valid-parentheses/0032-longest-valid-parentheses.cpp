class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0;
        stack<int> stk;
        stk.push(-1);
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '(') stk.push(i);
            else{
                stk.pop();
                if(stk.empty()) stk.push(i);
                else maxlen = max(maxlen, i - stk.top());
            }
        }
        return maxlen;
    }
};