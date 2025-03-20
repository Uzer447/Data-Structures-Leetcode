#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string lastSubstring(string s) {
        int n = s.size(), i = 0, j = 1, k = 0;
        while (j < n && i + k < n) {
            if (s[i+k] == s[j+k]) {
                k++;
            } else if (s[i+k] < s[j+k]) {
                i = max(i + k + 1, j);
                j = i + 1;
                k = 0;
            } else {
                j = j + k + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};