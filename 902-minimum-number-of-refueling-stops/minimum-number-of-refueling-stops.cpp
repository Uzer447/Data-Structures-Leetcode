#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int fuel = startFuel, ans = 0, prev = 0;
        int n = stations.size();
        for (int i = 0; i <= n; i++){
            int pos = (i == n ? target : stations[i][0]);
            int needed = pos - prev;
            while(fuel < needed && !pq.empty()){
                fuel += pq.top();
                pq.pop();
                ans++;
            }
            if(fuel < needed)
                return -1;
            fuel -= needed;
            prev = pos;
            if(i < n)
                pq.push(stations[i][1]);
        }
        return ans;
    }
};