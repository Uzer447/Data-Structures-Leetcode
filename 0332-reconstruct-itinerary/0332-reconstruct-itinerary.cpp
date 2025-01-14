class Solution {
public:
    vector<string> itinerary;
    unordered_map<string, vector<string>> graph;
    void dfs(const string& airport) {
        auto& dests = graph[airport];
        while (!dests.empty()) {
            string next_airport = dests.back();
            dests.pop_back();
            dfs(next_airport);
        }
        itinerary.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
        }
        for (auto& pair : graph) {
            sort(pair.second.rbegin(), pair.second.rend());
        }
        dfs("JFK");
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};