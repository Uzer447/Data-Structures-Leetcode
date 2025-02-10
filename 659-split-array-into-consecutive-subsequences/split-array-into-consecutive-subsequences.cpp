class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> fre;
        for(int x:nums)
        {
            fre[x]++;
        }
        unordered_map<int,int> need;
        for(int n:nums)
        {
            if(fre[n]==0)
            {
                continue;
            }
            if(need[n]>0)
            {
                need[n]--;
                fre[n]--;
                need[n+1]++;
            }
            else if (fre[n]>0 && fre[n+1]>0 && fre[n+2]>0)
            {
                fre[n]--;
                fre[n+1]--;
                fre[n+2]--;
                need[n+3]++;
            }
            else 
            {
                return false;
            }
        }
        return true;
    }
};