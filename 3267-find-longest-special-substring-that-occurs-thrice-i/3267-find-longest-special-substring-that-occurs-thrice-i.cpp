class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            set<char> st;
            string str = "";
            for (int j = i; j < n; j++) {
                str = str + s[j];
                st.insert(s[j]);
                if (st.size() == 1) {
                    mp[str]++;
                } else
                    break;
            }
        }
        int maxlen=0;
        for (auto it : mp) {
            if (it.second >= 3)
            {
                int temp=it.first.size();
                maxlen=max(maxlen,temp);
            }
        }
        if(maxlen!=0)
        return maxlen;
        return -1;
    }
};