class Solution {
    using ll = long long;
    static constexpr ll MOD = 1'000'000'007;
    using vec = array<ll,26>;
    using mat = array<vec,26>;

    static vec mul(const vec& v, const mat& M){
        vec r{};
        for(int i=0;i<26;++i){
            if(!v[i]) continue;
            for(int j=0;j<26;++j)
                if(M[i][j])
                    r[j] = (r[j] + v[i]*M[i][j]) % MOD;
        }
        return r;
    }

    static mat mul(const mat& A, const mat& B){
        mat R{};
        for(int i=0;i<26;++i)
            for(int k=0;k<26;++k){
                if(!A[i][k]) continue;
                for(int j=0;j<26;++j)
                    if(B[k][j])
                        R[i][j] = (R[i][j] + A[i][k]*B[k][j]) % MOD;
            }
        return R;
    }

public:
    int lengthAfterTransformations(string s, long long t, vector<int>& nums) {
        vec v{};
        for(char c : s) ++v[c-'a'];

        mat M{};
        for(int i=0;i<26;++i)
            for(int k=1;k<=nums[i];++k)
                M[i][(i+k)%26] = 1;

        while(t){
            if(t & 1) v = mul(v, M);
            M = mul(M, M);
            t >>= 1;
        }

        ll ans = 0;
        for(ll x : v) ans = (ans + x) % MOD;
        return int(ans);
    }
};