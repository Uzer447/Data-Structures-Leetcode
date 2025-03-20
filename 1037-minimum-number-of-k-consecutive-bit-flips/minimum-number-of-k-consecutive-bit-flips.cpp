#include <vector>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), res = 0, cur = 0;
        vector<int> flipped(n, 0);
        for (int i = 0; i < n; i++) {
            if (i >= k) cur ^= flipped[i - k];
            if ((nums[i] ^ cur) == 0) {
                if (i + k > n) return -1;
                flipped[i] = 1;
                cur ^= 1;
                res++;
            }
        }
        return res;
    }
};