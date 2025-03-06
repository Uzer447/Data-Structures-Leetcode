class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalNumbers = n * n;
        int xor_total = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                xor_total ^= grid[i][j];
            }
        }
        for (int num = 1; num <= totalNumbers; num++) {
            xor_total ^= num;
        }
        int setBit = xor_total & -xor_total; 
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] & setBit)
                    x ^= grid[i][j];
                else
                    y ^= grid[i][j];
            }
        }
        for (int num = 1; num <= totalNumbers; num++) {
            if (num & setBit)
                x ^= num;
            else
                y ^= num;
        }
        int duplicate = 0, missing = 0;
        int countX = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == x)
                    countX++;
            }
        }

        if (countX == 2) {
            duplicate = x;
            missing = y;
        } else {
            duplicate = y;
            missing = x;
        }

        return {duplicate, missing};
    }
};