class Solution {
public:
    bool checkValidString(string s) {
        int mine=0;
        int maxe=0;
        for(auto it:s)
        {
            if(it=='(')
            {
                mine++;
                maxe++;
            }
            else if(it==')')
            {
                mine--;
                maxe--;
            }
            else
            {
                mine--;
                maxe++;
            }
            if(maxe<0)
            return false;
            if(mine<0)
            mine=0;
        }
        if(mine==0)
        return true;
        return false;
    }
};