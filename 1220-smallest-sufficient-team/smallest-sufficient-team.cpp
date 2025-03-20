#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        unordered_map<string, int> skill_index;
        for (int i = 0; i < n; ++i)
            skill_index[req_skills[i]] = i;
        int m = people.size();
        vector<int> person_mask(m, 0);
        for (int i = 0; i < m; ++i) {
            int mask = 0;
            for (auto& skill : people[i])
                if (skill_index.count(skill))
                    mask |= 1 << skill_index[skill];
            person_mask[i] = mask;
        }
        unordered_map<int, vector<int>> dp;
        dp[0] = {};
        for (int i = 0; i < m; ++i) {
            if (person_mask[i] == 0) continue;
            auto current = dp;
            for (auto& kv: current) {
                int comb = kv.first | person_mask[i];
                if (!dp.count(comb) || dp[comb].size() > kv.second.size() + 1) {
                    dp[comb] = kv.second;
                    dp[comb].push_back(i);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};