class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();

        vector<int> lastocc(m,-1);
        int i=n-1,j=m-1;
        while(i>=0 && j>=0){
            if(word1[i]==word2[j]){
                lastocc[j]=i;
                j--;
                i--;
            }else{
                i--;
            }
        }

        vector<int> ans;
        int changed=0;

        j=0;
        for(i=0;i<n;i++){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }else if(!changed){
                if((j<m-1 && lastocc[j+1]>=i+1) || (j==m-1)){
                    changed++;
                    ans.push_back(i);
                    j++;
                }
            }
            if(j>=m)break;
        }
        if(ans.size()!=m)return {};
        return ans;
    }
};