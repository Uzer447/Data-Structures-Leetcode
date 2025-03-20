#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size(), n = target.size(), stars = 0;
        vector<bool> done(n - m + 1, false);
        vector<int> ans;
        while(stars < n) {
            bool changed = false;
            for (int i = 0; i <= n - m; i++) {
                if (!done[i] && canReplace(target, i, stamp)) {
                    int replaced = replace(target, i, m);
                    if (replaced > 0) {
                        stars += replaced;
                        done[i] = true;
                        changed = true;
                        ans.push_back(i);
                        if (stars == n) break;
                    }
                }
            }
            if (!changed) return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    bool canReplace(const string &s, int pos, const string &stamp) {
        int m = stamp.size();
        for (int i = 0; i < m; i++) {
            if (s[pos + i] != '?' && s[pos + i] != stamp[i]) return false;
        }
        return true;
    }
    int replace(string &s, int pos, int m) {
        int count = 0;
        for (int i = 0; i < m; i++) {
            if (s[pos + i] != '?') {
                s[pos + i] = '?';
                count++;
            }
        }
        return count;
    }
};