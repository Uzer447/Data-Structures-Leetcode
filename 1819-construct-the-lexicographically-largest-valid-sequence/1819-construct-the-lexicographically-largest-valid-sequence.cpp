class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, 0);
        unordered_set<int> used;
        backtrack(result, used, 0, n);
        return result;
    }

private:
    bool backtrack(vector<int>& result, unordered_set<int>& used, int index, int n) {
        if (index == result.size()) {
            return true;
        }

        if (result[index] != 0) {
            return backtrack(result, used, index + 1, n);
        }

        for (int num = n; num >= 1; --num) {
            if (used.find(num) != used.end()) continue;
            if (num == 1) {
                result[index] = 1;
                used.insert(1);
                if (backtrack(result, used, index + 1, n)) {
                    return true;
                }
                used.erase(1);
                result[index] = 0;
            } else {
                if (index + num < result.size() && result[index + num] == 0) {
                    result[index] = num;
                    result[index + num] = num;
                    used.insert(num);
                    if (backtrack(result, used, index + 1, n)) {
                        return true;
                    }
                    used.erase(num);
                    result[index] = 0;
                    result[index + num] = 0;
                }
            }
        }

        return false;
    }
};