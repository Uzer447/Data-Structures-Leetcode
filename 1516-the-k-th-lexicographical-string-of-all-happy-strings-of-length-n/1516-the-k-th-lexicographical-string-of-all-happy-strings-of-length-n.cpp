#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHappyString(int n, int k) {
        string res, path;
        int cnt = 0;
        function<bool()> dfs = [&]() -> bool {
            if (path.size() == n) {
                cnt++;
                if (cnt == k) {
                    res = path;
                    return true;
                }
                return false;
            }
            for (char ch : {'a', 'b', 'c'}) {
                if (!path.empty() && path.back() == ch)
                    continue;
                path.push_back(ch);
                if (dfs())
                    return true;
                path.pop_back();
            }
            return false;
        };
        dfs();
        return res;
    }
};