class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int total = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if (total % n != 0) return -1;
        int target = total / n;
        int res = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            int delta = machines[i] - target;
            sum += delta;
            res = max(res, max(abs(sum), delta));
        }
        return res;
    }
};