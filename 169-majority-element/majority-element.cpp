class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int ele=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0)
            {
                ele=nums[i];
                cnt=1;
            }
            else if(nums[i]==ele)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return ele;
    }
};