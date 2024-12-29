class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        if (numFriends == 1) {
            // Only one friend, the entire word is collected
            return word;
        } else if (numFriends == n) {
            // Each friend gets one character; return the lex largest character
            char max_char = *max_element(word.begin(), word.end());
            return string(1, max_char);
        } else {
            int L = n - numFriends + 1; // Maximum possible length of a part
            // Find the lexicographically largest character in the word
            char max_char = *max_element(word.begin(), word.end());
            string max_substring = "";
            // Positions where the character is equal to the max_char
            vector<int> positions;
            for (int i = 0; i < n; ++i) {
                if (word[i] == max_char) {
                    positions.push_back(i);
                }
            }
            // Consider substrings starting at positions of max_char with length
            // up to L
            for (int i : positions) {
                int end = min(i + L, n);
                string s = word.substr(i, end - i);
                if (s > max_substring) {
                    max_substring = s;
                }
            }
            return max_substring;
        }
    }
};