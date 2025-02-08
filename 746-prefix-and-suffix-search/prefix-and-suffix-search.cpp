class WordFilter {
public:
    unordered_map<string, int> mp;
    WordFilter(vector<string>& words) {
        int N = words.size();
        for (int index = 0; index < N; ++index) {
            string word = words[index];
            int len = word.length();
            for (int i = 0; i <= len; ++i) {
                string p = word.substr(0, i);
                for (int j = 0; j <= len; ++j) {
                    string s = word.substr(len - j, j);
                    mp[p + '#' + s] = index;
                }
            }
        }
    }
    int f(string pref, string suff) {
        auto it = mp.find(pref + '#' + suff);
        return it == mp.end() ? -1 : it->second;
    }
};