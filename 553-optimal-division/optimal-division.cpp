/*
    2 3 4= (2/3)/4=0.15
    2/(3/4)=2.66
    2/3/4=0.15

    1000 100 10 2= 1000/(100/10/2)= 
    2 3 4= 2/(3/4)=2.66

    100 1 1 1= 100/(1/1/1)=100

*/
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if(nums.size()==1)
            return to_string(nums[0]);
        if(nums.size()==2)
            return to_string(nums[0])+"/"+to_string(nums[1]);
        string res=to_string(nums[0]);
        res+="/(";
        for(int i=1;i<nums.size();i++)
        {
            res+=to_string(nums[i]);
            if(i!=nums.size()-1)
                res+="/";
        }
        res+=")";
        return res;
    }
};