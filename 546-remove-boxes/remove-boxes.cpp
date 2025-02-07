#include <vector>
#include <unordered_map>
#include <tuple>

class Solution {
public:
    using State = std::tuple<int, int, int>;
    struct StateHash {
        size_t operator()(const State& s) const {
            return ((size_t)std::get<0>(s) << 20) ^ ((size_t)std::get<1>(s) << 10) ^ (size_t)std::get<2>(s);
        }
    };
    
    std::unordered_map<State, int, StateHash> memo;
    
    int dfs(std::vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;

        State key = std::make_tuple(l, r, k);
        if (memo.count(key)) return memo[key];

        // Optimization: Merge boxes of the same color adjacent to boxes[r]
        while (l < r && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }

        // Remove boxes[r] with count k
        int res = dfs(boxes, l, r - 1, 0) + (k + 1) * (k + 1);

        // Try to merge non-contiguous boxes of the same color
        for (int m = l; m < r; ++m) {
            if (boxes[m] == boxes[r]) {
                res = std::max(res, dfs(boxes, l, m, k + 1) + dfs(boxes, m + 1, r - 1, 0));
            }
        }

        memo[key] = res;
        return res;
    }
    
    int removeBoxes(std::vector<int>& boxes) {
        memo.clear();
        return dfs(boxes, 0, boxes.size() - 1, 0);
    }
};