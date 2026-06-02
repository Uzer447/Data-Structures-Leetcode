class Solution {
public:
    int uniquePaths(int m, int n) {
        int x=m+n-2;
        int r=n-1;
        long long res=1;
        for(int i=1;i<=r;i++){
            res=res*(x-r+i)/i;
        }
        return res;
    }
};