class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long prefix = 0, minPrefix = 0, maxPrefix = 0;
        for (int d : differences) {
            prefix += d;
            minPrefix = min(minPrefix, prefix);
            maxPrefix = max(maxPrefix, prefix);
        }
        long long low = (long long)lower - minPrefix;
        long long high = (long long)upper - maxPrefix;
        return low > high ? 0 : (int)(high - low + 1);
    }
};