class Solution {
public:
    bool isSubsequence(string a,string b){
        int i=0;
        int j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]==b[j]) i++;
            j++;
        }
        return i==a.size();
    }
    int findLUSlength(vector<string>& strs) {
        unordered_map<string, int> freq;
        for (const string &s : strs) freq[s]++;

        int maxLength=-1;
        for(int i=0;i<strs.size();i++){
            if (freq[strs[i]] > 1) continue;
            bool possibleCandidate=true;
            for(int j=0;j<strs.size();j++){
                if(i!=j && isSubsequence(strs[i],strs[j])){
                    possibleCandidate=false;
                    break;
                }
            }
            if(possibleCandidate) maxLength = max(maxLength, static_cast<int>(strs[i].size()));

       }
       return maxLength; 

    }
};