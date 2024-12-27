class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_score = 0;
        int max_i =values[0]+0;
        for (int j = 1; j < values.size(); ++j) {
            int current_score = max_i + values[j] - j;
            max_score = max(max_score, current_score);
            max_i = max(max_i, values[j] + j);
        }
        return max_score;
    }
};