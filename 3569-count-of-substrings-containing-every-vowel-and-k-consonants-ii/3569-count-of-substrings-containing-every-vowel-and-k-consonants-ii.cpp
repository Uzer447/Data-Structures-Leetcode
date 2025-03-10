class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        vector<vector<int>> nxt(5, vector<int>(n, n));
        string v = "aeiou";
        for (int j = 0; j < 5; j++) {
            int cur = n;
            for (int i = n - 1; i >= 0; i--) {
                if (word[i] == v[j]) cur = i;
                nxt[j][i] = cur;
            }
        }
        vector<int> cons(n + 1, 0);
        for (int i = 0; i < n; i++)
            cons[i + 1] = cons[i] + ((word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u')?0:1);
        vector<vector<int>> bucket(n + 1);
        for (int t = 0; t <= n; t++)
            bucket[cons[t]].push_back(t);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int tar = cons[i] + k;
            if(tar > n) continue;
            int pos = 0;
            for (int j = 0; j < 5; j++)
                pos = max(pos, nxt[j][i]);
            if(pos == n) continue;
            auto &vec = bucket[tar];
            auto it = std::lower_bound(vec.begin(), vec.end(), pos + 1);
            ans += vec.end() - it;
        }
        return ans;
    }
};