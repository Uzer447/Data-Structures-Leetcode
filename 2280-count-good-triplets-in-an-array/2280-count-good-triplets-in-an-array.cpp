struct Fenw {
    int n;
    vector<int> f;
    Fenw(int n): n(n), f(n+1, 0) {}
    void update(int i, int delta) {
        i++;
        while(i <= n) {
            f[i] += delta;
            i += i & -i;
        }
    }
    int query(int i) {
        int s = 0;
        i++;
        while(i) {
            s += f[i];
            i -= i & -i;
        }
        return s;
    }
};
 
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos(n);
        for(int i = 0; i < n; i++) pos[nums2[i]] = i;
        vector<int> B(n);
        for(int i = 0; i < n; i++) B[i] = pos[nums1[i]];
        vector<long long> left(n), right(n);
        Fenw fenw(n);
        for(int i = 0; i < n; i++){
            left[i] = (B[i] > 0 ? fenw.query(B[i]-1) : 0);
            fenw.update(B[i], 1);
        }
        Fenw fenw2(n);
        for(int i = n-1; i >= 0; i--){
            right[i] = (B[i] < n-1 ? fenw2.query(n-1) - fenw2.query(B[i]) : 0);
            fenw2.update(B[i], 1);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += left[i] * right[i];
        }
        return ans;
    }
};