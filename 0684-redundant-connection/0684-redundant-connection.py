class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        def find(parent, u):
            if parent[u] != u:
                parent[u] = find(parent, parent[u])  
            return parent[u]
        
        def union(parent, u, v):
            pu = find(parent, u)
            pv = find(parent, v)
            if pu == pv:
                return False  
            parent[pu] = pv
            return True  
        
        n = len(edges)
        parent = [i for i in range(n + 1)] 
        
        for u, v in edges:
            if not union(parent, u, v):
                return [u, v] 
        return []