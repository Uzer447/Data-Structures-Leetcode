class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int freq[101] = {0};
        for (int x : nums) freq[x]++;
        int dup = 0;
        for (int i = 1; i <= 100; i++){
            if(freq[i] > 1) dup++;
        }
        if(dup == 0) return 0;
        int ops = 0, idx = 0;
        while(idx < n){
            for (int i = 0; i < 3 && idx < n; i++, idx++){
                int x = nums[idx];
                if(freq[x] == 2) dup--;
                freq[x]--;
            }
            ops++;
            if(dup == 0) return ops;
        }
        return ops;
    }
};