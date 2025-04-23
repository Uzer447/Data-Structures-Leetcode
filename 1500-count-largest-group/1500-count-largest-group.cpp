class Solution {
public:
    int countLargestGroup(int n) {
        int freq[37] = {0};
        vector<int> s(n + 1);
        for (int i = 1; i <= n; ++i) {
            s[i] = s[i / 10] + i % 10;
            ++freq[s[i]];
        }
        int mx = *max_element(begin(freq), end(freq));
        return count(begin(freq), end(freq), mx);
    }
};