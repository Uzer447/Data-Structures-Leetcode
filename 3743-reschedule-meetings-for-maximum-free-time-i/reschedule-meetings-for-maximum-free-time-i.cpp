class Solution {
public:
    int helper(int eventTime, int k, vector<int>& startTime,
               vector<int>& endTime) {
        int n = startTime.size();
        vector<long long> dur(n);
        vector<long long> pref(n);
        for (int i = 0; i < n; i++) {
            dur[i] = endTime[i] - startTime[i];
            pref[i] = dur[i] + (i > 0 ? pref[i - 1] : 0);
        }

        long long maxans = 0;
        maxans = startTime[0];

        maxans = max(maxans, (long long)eventTime - endTime[n - 1]);

        for (int l = 0; l <= n - k; l++) {
            int r = l + k - 1;
            long long t = (l > 0) ? endTime[l - 1] : 0;
            long long tot = pref[r] - (l > 0 ? pref[l - 1] : 0);
            long long newend = t + tot;

            long long free;
            if (r + 1 < n) {
                free = startTime[r + 1] - newend;
            } else {
                free = eventTime - newend;
            }
            if (free > maxans) {
                maxans = free;
            }
        }

        if (k >= n) {
            long long tot = pref[n - 1];
            long long free = eventTime - tot;
            if (free > maxans) {
                maxans = free;
            }
        }

        return (int)maxans;
    }
    int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                    vector<int>& endTime) {
        return helper(eventTime, k, startTime, endTime);
    }
};