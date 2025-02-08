#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
            return 0;
        
        unordered_map<int, vector<int>> stop_to_buses;
        int n = routes.size();
        for (int bus = 0; bus < n; ++bus) {
            for (int stop : routes[bus]) {
                stop_to_buses[stop].push_back(bus);
            }
        }
        
        vector<unordered_set<int>> bus_routes(n);
        for (int i = 0; i < n; ++i) {
            bus_routes[i].insert(routes[i].begin(), routes[i].end());
        }
        
        vector<unordered_set<int>> bus_graph(n);
        for (const auto& [stop, buses] : stop_to_buses) {
            for (int i = 0; i < buses.size(); ++i) {
                int bus1 = buses[i];
                for (int j = i + 1; j < buses.size(); ++j) {
                    int bus2 = buses[j];
                    bus_graph[bus1].insert(bus2);
                    bus_graph[bus2].insert(bus1);
                }
            }
        }
        
        queue<pair<int, int>> q;
        vector<bool> visited_buses(n, false);
        for (int bus : stop_to_buses[source]) {
            q.emplace(bus, 1);
            visited_buses[bus] = true;
        }
        
        while (!q.empty()) {
            auto [current_bus, buses_taken] = q.front();
            q.pop();
            if (bus_routes[current_bus].count(target))
                return buses_taken;
            for (int neighbor_bus : bus_graph[current_bus]) {
                if (!visited_buses[neighbor_bus]) {
                    visited_buses[neighbor_bus] = true;
                    q.emplace(neighbor_bus, buses_taken + 1);
                }
            }
        }
        return -1;
    }
};