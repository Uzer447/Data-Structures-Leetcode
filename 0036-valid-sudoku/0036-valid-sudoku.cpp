class Solution {
public:
    bool loang(vector<vector<char>>& a) {
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                map<char, int> check;
                for (int l = i; l < i + 3; l++) {
                    for (int r = j; r < j + 3; r++) {
                        if (isdigit(a[l][r])) {
                            check[a[l][r]]++;
                            if (check[a[l][r]] == 2)
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& a) {
        map<char, int> check1;
        map<char, int> check2;
        for (int i = 0; i < 9; i++) {
            check1.clear();
            check2.clear();
            for (int j = 0; j < 9; j++) {
                if (isdigit(a[i][j]))
                    check1[a[i][j]]++;
                if (isdigit(a[j][i]))
                    check2[a[j][i]]++;
                if (check1[a[i][j]] == 2 || check2[a[j][i]] == 2)
                    return false;
            }
        }
        return loang(a);
    }
};