class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for(int i=0;i<asteroids.size();i++)
        {
            if(asteroids[i]>0)
            st.push_back(asteroids[i]);
            else
            {
                while(st.size() && st.back()>0 && st.back()<abs(asteroids[i]))
                st.pop_back();
                if(st.size() && st.back()==abs(asteroids[i]))
                st.pop_back();
                else if(st.size()==0 || st.back()<0)
                st.push_back(asteroids[i]);
            }
        }
        return st;
    }
};