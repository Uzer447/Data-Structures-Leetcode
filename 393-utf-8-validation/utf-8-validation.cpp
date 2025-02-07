class Solution {
    int EIGHT = 0b10000000;
    int ONE = 0b11000000;
    int TWO = 0b11100000;
    int THREE = 0b11110000;
    int FOUR = 0b11111000;

    bool isOneByte(int n)
    {
        return (n & EIGHT) == 0;
    }

    int countBytes(int n)
    {
        if( (n & TWO) == 0b11000000) return 2; 
        else if( (n & THREE) == 0b11100000) return 3; 
        else if( (n & FOUR) == 0b11110000) return 4; 
        return -1; 
    }

    bool checkNext(vector<int>& data, int s, int count)
    {
        if(s+count-1 >= data.size()) return false; 

        for(int i=s; i<s+count; i++){
            int n = data[i]; 
            if( (n & ONE) != 0b10000000) return false; 
        }

        return true; 
    }

public:
    bool validUtf8(vector<int>& data) {
        int n = data.size(); 
        int i = 0; 

        while(i<n){
            if(isOneByte(data[i])){
                i++;
            }
            else{
                int count = countBytes(data[i]); 
                if(count == -1) return false; 

                bool ans = checkNext(data, i+1, count - 1); 
                if(!ans) return false; 

                i += (count);
            }
        }

        return true; 
    }
};