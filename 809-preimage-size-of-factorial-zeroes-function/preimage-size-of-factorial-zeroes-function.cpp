class Solution {
public:
    int preimageSizeFZF(int k) {
        auto f=[](long long x){
            long long res=0;
            while(x){
                x/=5;
                res+=x;
            }
            return res;
        };
        auto getLeft=[&](int k){
            long long left=0,right=5LL*(k+1);
            while(left<right){
                long long mid=left+(right-left)/2;
                if(f(mid)<k)
                    left=mid+1;
                else
                    right=mid;
            }
            return left;
        };
        auto getRight=[&](int k){
            long long left=0,right=5LL*(k+1);
            while(left<right){
                long long mid=left+(right-left)/2;
                if(f(mid)<=k)
                    left=mid+1;
                else
                    right=mid;
            }
            return left;
        };
        return getRight(k)-getLeft(k);
    }
};