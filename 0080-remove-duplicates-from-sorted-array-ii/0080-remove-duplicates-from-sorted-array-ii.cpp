class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int elem:nums){
            if(i<2 || elem!=nums[i-2]){
                nums[i]=elem;
                i++;
            }
        }
        return i;
    
    }
};