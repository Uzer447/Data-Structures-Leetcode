class Solution {
    int eval(int x,const vector<int>& A,const vector<int>& B){
        int rt=0,rb=0,n=A.size();
        for(int i=0;i<n;++i){
            if(A[i]!=x&&B[i]!=x) return INT_MAX;
            if(A[i]!=x) ++rt;
            if(B[i]!=x) ++rb;
        }
        return min(rt,rb);
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int a=eval(tops[0],tops,bottoms);
        int b=eval(bottoms[0],tops,bottoms);
        int res=min(a,b);
        return res==INT_MAX?-1:res;
    }
};