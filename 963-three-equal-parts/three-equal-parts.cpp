#include <vector>
using namespace std;
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size(), ones = 0;
        for (int bit : arr) ones += bit;
        if (ones == 0) return {0, n - 1};
        if (ones % 3 != 0) return {-1, -1};
        int onesPerPart = ones / 3, first = -1, second = -1, third = -1, count = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] == 1) {
                count++;
                if (count == 1) first = i;
                if (count == onesPerPart + 1) second = i;
                if (count == 2 * onesPerPart + 1) third = i;
            }
        }
        int len = n - third;
        if (first + len > second || second + len > third) return {-1, -1};
        for (int i = 0; i < len; i++){
            if (arr[first + i] != arr[second + i] || arr[first + i] != arr[third + i])
                return {-1, -1};
        }
        return {first + len - 1, second + len};
    }
};