typedef tuple<int, int, int> ti; // Tuple to store {time, row, column}.
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<int> dir = {-1, 0, 1, 0, -1};
        int n=grid.size();

        vector<vector<int>> dist(n, vector<int>(n, 1e9)); // just used to keep track of minimum time in which we can reach a cell
        dist[0][0] = grid[0][0]; // Starting point has time equal to its height.

        set<ti> s; // Set used as a priority queue for Dijkstra's algorithm.
        s.insert({grid[0][0], 0, 0}); // Start with the top-left corner.

        // running shortest path logic
        while (s.size()) {
            auto top = *(s.begin()); // Get the cell with the least time.
            auto [curTime, i, j] = top;
            
            s.erase(top);

            // If we reach the bottom-right cell, return the time.
            if (i==n-1 and j==n-1) return dist[i][j];

            // Process all 4 neighbors.
            for (int k=0; k<4; k++) {
                int x=i+dir[k], y=j+dir[k+1];
                if (x>=0 and y>=0 and x<n and y<n) { // Check if the neighbor is within the grid bounds.

                    // Case 1: Neighbor's height is less than or equal to current cell's height.
                    if (grid[x][y] <= grid[i][j] and curTime < dist[x][y]) {
                        if (dist[x][y] != 1e9) s.erase({dist[x][y], x, y}); // Remove old entry if present.

                        dist[x][y] = curTime; // Update the neighbor's time.
                        s.insert({dist[x][y], x, y}); // Insert updated time into the set.
                    }

                    // Case 2: Neighbor's height is greater than current cell's height.
                    else if (dist[x][y] == 1e9) { // we explore only an unexplored cell. if a cell is explored then don't bother about it again, this is because any cell can't be revisited with a shorter time and the first time it's explored, it's the shortest time path
                        dist[x][y] = max(grid[x][y], curTime);
                        s.insert({dist[x][y], x, y});
                    }
                }

            }

        }

        return dist.back().back();
    }
};