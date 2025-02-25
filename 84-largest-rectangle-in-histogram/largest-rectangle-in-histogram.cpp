class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int maxarea=0;
        for(int i=0;i<heights.size();i++)
        {
            int start=i;
            while(!st.empty() && st.top().second>heights[i])
            {
                int idx=st.top().first;
                int ele=st.top().second;
                maxarea=max(maxarea,(i-idx)*ele);
                start=idx;
                st.pop();
            }
            st.push({start,heights[i]});
        }
        int n=heights.size();
        while(!st.empty())
        {
            int idx=st.top().first;
            int ele=st.top().second;
            st.pop();
            maxarea=max(maxarea,(n-idx)*ele);
        }
        return maxarea;
    }
};