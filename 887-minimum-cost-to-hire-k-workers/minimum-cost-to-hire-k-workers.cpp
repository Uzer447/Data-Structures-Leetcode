class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;
        for (int i = 0; i < n; ++i) {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }
        sort(workers.begin(), workers.end());
        priority_queue<int> pq;
        long long total_quality = 0;
        double min_cost = 1e18;
        for (int i = 0; i < n; ++i) {
            int q = workers[i].second;
            double ratio = workers[i].first;
            total_quality += q;
            pq.push(q);
            if ((int)pq.size() > k) {
                total_quality -= pq.top();
                pq.pop();
            }
            if ((int)pq.size() == k) {
                double cost = total_quality * ratio;
                min_cost = min(min_cost, cost);
            }
        }
        return min_cost;
    }
};