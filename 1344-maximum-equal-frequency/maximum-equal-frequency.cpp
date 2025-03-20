#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size(), ans = 0, ctr = 0;
        if(n == 1)
            return 1;
        map<int, int> freq;
        set<int> st;
        vector<int> count(N, 0);
        for(auto num : nums) {
            if(count[num]) {
                freq[count[num]]--;
                if(freq[count[num]] == 0)
                    st.erase(count[num]);
                count[num]++;
                freq[count[num]]++;
                st.insert(count[num]);
            } else {
                count[num] = 1;
                freq[1]++;
                st.insert(1);
            }
            if(st.size() == 2) {
                int p1 = *st.begin(), p2 = *st.rbegin();
                if((p1 == 1 && freq[p1] == 1) || (p2 - p1 == 1 && freq[p2] == 1))
                    ans = max(ans, ctr + 1);
            }
            ctr++;
        }
        if(st.size() == 1 && (freq[*st.begin()] == 1 || *st.begin() == 1))
            return n;
        return ans;
    }
};