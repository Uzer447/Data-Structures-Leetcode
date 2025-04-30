class Solution {
public:
    int numofdigits(int n)
    {
        int digits=0;
        while(n!=0)
        {
            n/=10;
            digits++;
        }
        return digits;
    }
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(auto i:nums)
        {
            if(numofdigits(i)%2==0)
                count++;
        }
        return count;
    }
};