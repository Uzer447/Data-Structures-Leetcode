class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int n = words.size();
        vector<int> is_vowel_word(n, 0);

        // Preprocess words to check if they start and end with a vowel
        for (int i = 0; i < n; ++i) {
            const string& word = words[i];
            if (vowels.count(word.front()) && vowels.count(word.back())) {
                is_vowel_word[i] = 1;
            }
        }

        // Compute prefix sums for quick range query evaluation
        vector<int> prefix(n + 1, 0); // prefix[i+1] stores sum from index 0 to i
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + is_vowel_word[i];
        }

        vector<int> ans;
        ans.reserve(queries.size());

        // Answer each query using the prefix sums
        for (const auto& query : queries) {
            int li = query[0];
            int ri = query[1];
            int count = prefix[ri + 1] - prefix[li];
            ans.push_back(count);
        }

        return ans;
    }
};