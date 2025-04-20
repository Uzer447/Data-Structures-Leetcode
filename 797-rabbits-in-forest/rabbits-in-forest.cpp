class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int freq[1001] = {0};
        for(auto a : answers)
            freq[a]++;
        int res = 0;
        for(int i = 0; i < 1001; i++){
            if(freq[i]){
                res += ((freq[i] + i) / (i + 1)) * (i + 1);
            }
        }
        return res;
    }
};