class Compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first > b.first)
            return true;
        else if (a.first == b.first) {
            if (a.second > b.second)
                return true;
            else
                return false;
        }
        return false;
    }
};
class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        long long score = 0;
        vector<int> marked(n, 0);
        while (!pq.empty()) {
            int ele = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            if(marked[ind]==1)
            continue;
            score += ele;
            if (ind - 1 >= 0)
                marked[ind - 1] = 1;
            if (ind + 1 < n)
                marked[ind + 1] = 1;
        }
        return score;
    }
};