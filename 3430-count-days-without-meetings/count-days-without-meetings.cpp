#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
        int total = 0, start = -1, end = -1;
        for(auto &m : meetings){
            if(start == -1){
                start = m[0];
                end = m[1];
            } else {
                if(m[0] <= end + 1) {
                    end = max(end, m[1]);
                } else {
                    total += end - start + 1;
                    start = m[0];
                    end = m[1];
                }
            }
        }
        if(start != -1) total += end - start + 1;
        return days - total;
    }
};