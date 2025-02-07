class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector <int> result;
        map<int,int>mp;
        for (int i=0;i<nums.size();i++){
            mp[nums.at(i)]++;
        }
        for (auto i:mp){
            if(i.second==1){
                result.push_back(i.first);
            }
        }
        return result;
    }
};