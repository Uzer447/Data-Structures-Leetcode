class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int N = nums.size();
        int perimeter = reduce(nums.begin(), nums.end());        
        int possible_side = perimeter/4;

        if(perimeter != possible_side*4 || *max_element(nums.begin(), nums.end()) > possible_side)
            return false;
        
        int size = 1<<N;
        vector<int>dp(size, -1);
        dp[0]=0;

        for(int mask=1; mask<size; mask++){
            for(int i=0; i<N; i++){
                int neib = dp[mask^(1<<i)];
                if(mask&(1<<i) && neib>=0 && nums[i]+neib<=possible_side){
                    dp[mask] = (neib+nums[i])%possible_side;
                    break;
                }
            }
        }
        return dp.back() == 0;
    }
};