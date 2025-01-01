#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxScore(std::string s) {
        int N = s.length();
        std::vector<int> suffix_ones(N + 1, 0);
        for (int i = N - 1; i >= 0; --i) {
            suffix_ones[i] = suffix_ones[i + 1] + (s[i] == '1' ? 1 : 0);
        }
        int max_score = 0;
        int left_zeros = 0;
        for (int i = 1; i < N; ++i) {
            if (s[i - 1] == '0') {
                ++left_zeros;
            }
            int total_score = left_zeros + suffix_ones[i];
            max_score = std::max(max_score, total_score);
        }
        return max_score;
    }
};