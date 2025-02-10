class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> remainderMap;
        int Sum = 0;
        
        remainderMap[0] = -1;

        for (int i = 0; i < n; i++) {
            Sum += nums[i];
            
            int remainder = Sum % k;
            
            if (remainderMap.count(remainder)) {
                if (i - remainderMap[remainder] > 1) {
                    return true;
                }
            } 
            else {
                remainderMap[remainder] = i;
            }
        }
        
        return false;
    }
};