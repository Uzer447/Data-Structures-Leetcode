class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int maxcovered=0;
        int steps=0;
        for(int i=0;i<n;i++)
        {
            if(maxcovered>=n-1)
            {
                return steps;
            }
            maxcovered=max(maxcovered,nums[i]+i);
            steps++;
        }
        return -1;
    }
};