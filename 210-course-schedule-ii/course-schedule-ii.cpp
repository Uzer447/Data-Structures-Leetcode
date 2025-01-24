class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[])
	{
		vector<int> indegree(V,0);
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
	}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it:prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> order=topoSort(numCourses,adj);
        if(order.size()==numCourses)
        return order;
        return {};
    }
};