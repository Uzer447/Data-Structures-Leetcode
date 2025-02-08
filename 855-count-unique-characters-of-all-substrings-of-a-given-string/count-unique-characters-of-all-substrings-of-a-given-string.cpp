class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> pos[26];
        int N = s.length();
        for (int i = 0; i < 26; ++i)
            pos[i].push_back(-1);
        for (int i = 0; i < N; ++i)
            pos[s[i] - 'A'].push_back(i);
        for (int i = 0; i < 26; ++i)
            pos[i].push_back(N);
        long long res = 0;
        for (int i = 0; i < 26; ++i) {
            vector<int>& indices = pos[i];
            for (int j = 1; j + 1 < indices.size(); ++j)
                res += (long long)(indices[j] - indices[j - 1]) *
                       (indices[j + 1] - indices[j]);
        }
        return (int)res;
    }
};