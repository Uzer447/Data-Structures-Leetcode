class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](const string& a, const string& b) {
            return a.size() > b.size() || (a.size() == b.size() && a < b);
        });

        for (auto& word : dictionary) {
            int i = 0, j = 0;
            while (i < s.size() && j < word.size()) {
                if (s[i] == word[j]) j++;
                i++;
            }
            if (j == word.size()) return word;
        }
        return "";
    }
};