class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int bestDiag = -1, bestArea = 0;
        for (auto& d : dimensions) {
            int l = d[0], w = d[1];
            int diag = l * l + w * w;
            int area = l * w;
            if (diag > bestDiag) {
                bestDiag = diag;
                bestArea = area;
            } else if (diag == bestDiag && area > bestArea) {
                bestArea = area;
            }
        }
        return bestArea;
    }
};