class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea=0;
        stack<pair<int,int>> st;
        for(int i=0;i<heights.size();i++)
        {
            int start=i;
            while(!st.empty() && st.top().first>heights[i])
            {
                int ind=st.top().second;
                int height=st.top().first;
                st.pop();
                maxarea=max(maxarea,height*(i-ind));
                start=ind;
            }
            st.push({heights[i],start});
        }
        int n=heights.size();
        while(!st.empty())
        {
            int ind=st.top().second;
            int height=st.top().first;
            st.pop();
            maxarea=max(maxarea,height*(n-ind));
        }
        return maxarea;
    }
};