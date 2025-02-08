class Solution {
public:
    int kSimilarity(string s1, string s2) {
        if (s1 == s2) return 0;
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.push({s1, 0});
        visited.insert(s1);
        while (!q.empty()) {
            auto [current, level] = q.front(); q.pop();
            if (current == s2) return level;
            int i = 0;
            while (i < current.size() && current[i] == s2[i]) i++;
            for (int j = i + 1; j < current.size(); ++j) {
                if (current[j] == s2[i] && current[j] != s2[j]) {
                    string next_state = current;
                    swap(next_state[i], next_state[j]);
                    if (!visited.count(next_state)) {
                        visited.insert(next_state);
                        q.push({next_state, level + 1});
                    }
                }
            }
        }
        return -1;
    }
};