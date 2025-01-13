class Solution {
public:
    int minimumLength(string s) {
        int freq[26] = {0};
        for(char c : s) freq[c - 'a']++;
        int ans = 0;
        for(int cnt : freq) {
            if(cnt >= 3) ans += (cnt % 2 == 0) ? 2 : 1;
            else ans += cnt;
        }
        return ans;
    }
};