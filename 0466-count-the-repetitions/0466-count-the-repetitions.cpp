class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) return 0;
        int s1_count = 0, s2_count = 0, index_s2 = 0;
        int s1_len = s1.length(), s2_len = s2.length();
        vector<pair<int, int>> recall(s2_len + 1, make_pair(-1, -1));
        while (s1_count < n1) {
            s1_count++;
            for (int i = 0; i < s1_len; i++) {
                if (s1[i] == s2[index_s2]) {
                    index_s2++;
                    if (index_s2 == s2_len) {
                        s2_count++;
                        index_s2 = 0;
                    }
                }
            }
            if (recall[index_s2].first != -1) {
                int s1_count_prev = recall[index_s2].first;
                int s2_count_prev = recall[index_s2].second;
                int in_loop_s1_count = s1_count - s1_count_prev;
                int in_loop_s2_count = s2_count - s2_count_prev;
                int remain_s1_count = n1 - s1_count;
                int loops = remain_s1_count / in_loop_s1_count;
                s1_count += loops * in_loop_s1_count;
                s2_count += loops * in_loop_s2_count;
                break;
            } else {
                recall[index_s2] = make_pair(s1_count, s2_count);
            }
        }
        while (s1_count < n1) {
            s1_count++;
            for (int i = 0; i < s1_len; i++) {
                if (s1[i] == s2[index_s2]) {
                    index_s2++;
                    if (index_s2 == s2_len) {
                        s2_count++;
                        index_s2 = 0;
                    }
                }
            }
        }
        return s2_count / n2;
    }
};