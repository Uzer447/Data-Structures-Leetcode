class Solution {
    struct Node {
        long long p, t;
        double g;
        bool operator<(const Node& o) const { return g < o.g; }
    };
    static double gain(long long p, long long t) {
        return (double)(t - p) / (t * (t + 1.0));
    }
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<Node> pq;
        for (auto& v : classes) pq.push({v[0], v[1], gain(v[0], v[1])});
        while (extraStudents--) {
            auto cur = pq.top(); pq.pop();
            ++cur.p; ++cur.t;
            cur.g = gain(cur.p, cur.t);
            pq.push(cur);
        }
        long double s = 0;
        for (; !pq.empty(); pq.pop()) {
            auto cur = pq.top();
            s += (long double)cur.p / cur.t;
        }
        return (double)(s / classes.size());
    }
};