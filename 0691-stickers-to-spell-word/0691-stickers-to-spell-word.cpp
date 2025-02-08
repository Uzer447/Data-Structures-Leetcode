class Solution {
public:
    int char_to_index[26], n_chars_in_target;
    vector<int> target_counts;
    vector<vector<int>> stickers_counts;
    int n_stickers;
    unordered_map<long long, int> memo;

    int minStickers(vector<string>& stickers, string target) {
        memset(char_to_index, -1, sizeof(char_to_index));
        n_chars_in_target = 0;
        for (char c : target)
            if (char_to_index[c - 'a'] == -1)
                char_to_index[c - 'a'] = n_chars_in_target++;
        target_counts.resize(n_chars_in_target);
        for (char c : target)
            target_counts[char_to_index[c - 'a']]++;

        n_stickers = stickers.size();
        stickers_counts.resize(n_stickers, vector<int>(n_chars_in_target));
        for (int i = 0; i < n_stickers; ++i)
            for (char c : stickers[i])
                if (char_to_index[c - 'a'] != -1)
                    stickers_counts[i][char_to_index[c - 'a']]++;

        memo.clear();
        int res = dfs(target_counts);
        return res;
    }

    int dfs(vector<int>& counts) {
        long long key = 0;
        for (int i = 0; i < counts.size(); ++i)
            key = (key << 4) | counts[i];
        if (memo.count(key))
            return memo[key];

        bool done = true;
        for (int cnt : counts)
            if (cnt > 0) {
                done = false;
                break;
            }
        if (done) {
            memo[key] = 0;
            return 0;
        }

        int res = INT_MAX;
        for (int i = 0; i < n_stickers; ++i) {
            if (!canContribute(stickers_counts[i], counts))
                continue;
            vector<int> new_counts(counts);
            for (int j = 0; j < n_chars_in_target; ++j)
                new_counts[j] = max(0, new_counts[j] - stickers_counts[i][j]);
            int tmp = dfs(new_counts);
            if (tmp != -1)
                res = min(res, tmp + 1);
        }
        memo[key] = (res == INT_MAX) ? -1 : res;
        return memo[key];
    }

    bool canContribute(vector<int>& sticker, vector<int>& counts) {
        for (int j = 0; j < n_chars_in_target; ++j)
            if (counts[j] > 0 && sticker[j] > 0)
                return true;
        return false;
    }
};