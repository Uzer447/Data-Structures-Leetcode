class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int l=0;
        int n=height.size();
        int r=n-1;
        while(l<r)
        {
            ans=max(ans,(r-l)*(min(height[l],height[r])));
            if(height[l]<height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};