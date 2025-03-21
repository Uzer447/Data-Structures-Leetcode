class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> indeg;
        for(auto &r : recipes)
            indeg[r] = 0;
        for(int i = 0; i < recipes.size(); i++){
            for(auto &ing : ingredients[i]){
                adj[ing].push_back(recipes[i]);
                indeg[recipes[i]]++;
            }
        }
        queue<string> q;
        for(auto &s : supplies)
            q.push(s);
        vector<string> res;
        while(!q.empty()){
            string cur = q.front();
            q.pop();
            for(auto &r : adj[cur]){
                if(--indeg[r] == 0){
                    res.push_back(r);
                    q.push(r);
                }
            }
        }
        return res;
    }
};