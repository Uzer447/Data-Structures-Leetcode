class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int h=0;
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int count=n-mid;
            if(citations[mid]>=count)
            {
                h=count;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return h;
    }
};