class Solution {
public:
    bool isPossible(vector<int> &arr,int mid,int k)
    {
        int cnt=1;int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            if(sum+arr[i]<=mid)
            {
                sum+=arr[i];
            }
            else
            {
                cnt++;
                sum=arr[i];
            }
        }
        if(cnt<=k)
            return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isPossible(nums,mid,k))
            high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
};