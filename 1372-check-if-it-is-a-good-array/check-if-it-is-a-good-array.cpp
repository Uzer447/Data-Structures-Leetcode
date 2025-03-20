#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = 0;
        for (auto n : nums)
            g = gcd(g, n);
        return g == 1;
    }
};