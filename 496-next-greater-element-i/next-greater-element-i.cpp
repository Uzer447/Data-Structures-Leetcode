class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int,int> nge;
        stack<int> st;
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<nums2[i])
            {
                st.pop();
            }
            if(st.empty())
            nge[nums2[i]]=-1;
            else
            nge[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        for(auto it:nums1)
        {
            ans.push_back(nge[it]);
        }
        return ans;
    }
};