class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<pair<int,int>> q;
        q.push({0,1});
        vector<int> color(graph.size(),0);
        color[0]=1;
        while(!q.empty()){
            int node=q.front().first;
            int col=q.front().second;
            q.pop();
            for(auto it:graph[node]){
                if(color[it]==0){
                    color[it]=col==1?2:1;
                    q.push({it,color[it]});
                } else if(color[it]==col){
                    return false;
                } else {
                    continue;
                }
            }
        }
        return true;
    }
};