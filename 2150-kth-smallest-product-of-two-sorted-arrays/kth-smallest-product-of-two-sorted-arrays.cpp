class Solution {
    static long long div_floor(long long x,long long y){
        long long q=x/y,r=x%y;
        if(r!=0 && ((r>0)!=(y>0))) --q;
        return q;
    }
    static long long div_ceil(long long x,long long y){
        long long q=x/y,r=x%y;
        if(r!=0 && ((r>0)==(y>0))) ++q;
        return q;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long mn=LLONG_MAX,mx=LLONG_MIN;
        long long a[]={nums1.front(),nums1.back()};
        long long b[]={nums2.front(),nums2.back()};
        for(long long x:a) for(long long y:b){
            long long p=x*y;
            mn=min(mn,p); mx=max(mx,p);
        }
        int m=nums2.size();
        auto cnt=[&](long long x)->long long{
            long long c=0;
            for(long long a:nums1){
                if(a==0){
                    if(x>=0) c+=m;
                }else if(a>0){
                    long long lim=div_floor(x,a);
                    c+=upper_bound(nums2.begin(),nums2.end(),lim)-nums2.begin();
                }else{
                    long long lim=div_ceil(x,a);
                    c+=nums2.end()-lower_bound(nums2.begin(),nums2.end(),lim);
                }
            }
            return c;
        };
        long long l=mn,r=mx;
        while(l<r){
            long long mid=l+((r-l)>>1);
            if(cnt(mid)>=k) r=mid;
            else l=mid+1;
        }
        return l;
    }
};