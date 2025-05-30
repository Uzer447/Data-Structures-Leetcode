class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt=0;
        while(num2>0)
        {
            if(num2%2==1)
            {
                cnt++;
            }
            num2/=2;
        }
        int x=0;
        int bitno=31;
        while(bitno>=0 && cnt>0)
        {
            if((num1&(1<<bitno))!=0)
            {
                x=x|(1<<bitno);
                cnt--;
            }
            bitno--;
        }
        bitno=0;
        while(bitno<=31 && cnt>0)
        {
            if((x&(1<<bitno))==0)
            {
                x=x|(1<<bitno);
                cnt--;
            }
            bitno++;
        }
        return x;
    }
};