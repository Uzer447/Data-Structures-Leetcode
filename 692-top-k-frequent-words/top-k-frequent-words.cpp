class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> result;
        unordered_map<string, int> mappings;
        for (int i = 0; i < words.size(); i++) {
            mappings[words[i]]++;
        }
        vector<pair<string, int>> sortedMappings(mappings.begin(),
                                                 mappings.end());
        sort(sortedMappings.begin(), sortedMappings.end(),
             [](const pair<string, int>& a, const pair<string, int>& b) {
                 if (a.second == b.second) {
                     return a.first < b.first;
                 }
                 return a.second > b.second;
             });
        for (int i = 0; i < k; i++) {
            result.push_back(sortedMappings[i].first);
        }
        return result;
    }
};