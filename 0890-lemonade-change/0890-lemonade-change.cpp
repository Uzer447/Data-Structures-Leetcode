class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        for(auto it:bills)
        {
            if(it==5)
            five++;
            else if(it==10)
            {
                if(five<1)
                return false;
                five--;
                ten++;
            }
            else
            {
                if(ten>0 && five>0)
                {
                    ten--;
                    five--;
                }
                else if(five>=3)
                {
                    five-=3;
                }
                else
                return false;
            }
        }
        return true;
    }
};