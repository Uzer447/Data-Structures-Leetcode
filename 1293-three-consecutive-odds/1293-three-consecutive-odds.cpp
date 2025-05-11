class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool flag=false;
        for(int i=2;i<arr.size();i++)
        {
            if(arr[i]%2==1 && arr[i]%2==arr[i-1]%2 && arr[i]%2==arr[i-2]%2)
            {
                flag=true;
                return flag;
            }
        }
        return flag;
    }
};