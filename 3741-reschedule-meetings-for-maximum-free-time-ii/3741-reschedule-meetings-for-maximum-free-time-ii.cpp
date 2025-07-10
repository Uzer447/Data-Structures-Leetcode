class Solution {
public:
    int helper(int endTime, vector<int>& startTimes, vector<int>& endTimes) {
        int task = startTimes.size();
        int numgap = task + 1;
        vector<int> gaps(numgap);
        gaps[0] = startTimes[0];
        for (int i = 1; i < task; i++)
            gaps[i] = startTimes[i] - endTimes[i - 1];
        gaps[numgap - 1] = endTime - endTimes[task - 1];
        int maxgap = *max_element(gaps.begin(), gaps.end());

        vector<int> prefmxg(numgap);
        prefmxg[0] = gaps[0];
        for (int i = 1; i < numgap; i++)
            prefmxg[i] = max(prefmxg[i - 1], gaps[i]);

        vector<int> suffmxgap(numgap);
        suffmxgap[numgap - 1] = gaps[numgap - 1];
        for (int i = numgap - 2; i >= 0; i--)
            suffmxgap[i] = max(suffmxgap[i + 1], gaps[i]);

        int res = maxgap;

        for (int i = 0; i < task; ++i) {
            int taskdur = endTimes[i] - startTimes[i];
            int combgap = 0;
            if (i == 0) {
                combgap = gaps[0] + taskdur + (task >= 2 ? gaps[1] : 0);
            } else if (i == task - 1) {
                combgap = gaps[task - 1] + taskdur + gaps[task];
            } else {
                combgap = gaps[i] + taskdur + gaps[i + 1];
            }
            int maxother = 0;
            if (i == 0 && numgap > 2) {
                maxother = suffmxgap[2];
            } else if (i == task - 1 && numgap > 2) {
                maxother = prefmxg[numgap - 3];
            } else if (i > 0 && i < task - 1) {
                int lmx = prefmxg[i - 1];
                int rmx = suffmxgap[i + 2];
                maxother = max(lmx, rmx);
            }
            int tempans = maxother >= taskdur ? combgap : combgap - taskdur;
            res = max(res, tempans);
        }

        return res;
    }
    int maxFreeTime(int endTime, vector<int>& startTimes,
                    vector<int>& endTimes) {
        return helper(endTime, startTimes, endTimes);
    }
};