class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        if (numFriends == 1) return word;
        if (numFriends == n) {
            char max_char = *max_element(word.begin(), word.end());
            return string(1, max_char);
        }
        int L = n - numFriends + 1;
        char max_char = *max_element(word.begin(), word.end());
        string max_substring = "";
        vector<int> positions;
        for (int i = 0; i < n; ++i) if (word[i] == max_char) positions.push_back(i);
        for (int i : positions) {
            int end = min(i + L, n);
            string s = word.substr(i, end - i);
            if (s > max_substring) max_substring = s;
        }
        return max_substring;
    }
};