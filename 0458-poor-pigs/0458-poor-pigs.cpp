class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t = minutesToTest / minutesToDie;
        int base = t + 1, pigs = 0, total = 1;
        while (total < buckets) {
            total *= base;
            pigs++;
        }
        return pigs;
    }
};