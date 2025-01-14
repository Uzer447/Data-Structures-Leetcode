class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> hash1;
        unordered_map<int,int> hash2;
        vector<int> result;
        for(int i=0;i<A.size();i++)
        {
            hash1[A[i]]=1;
            hash2[B[i]]=1;
            int ans=0;
            if(hash1[B[i]]==1)
            ans++;
            if(hash2[A[i]]==1)
            ans++;
            if(A[i]==B[i])
            ans--;
            if(result.size()==0)
            result.push_back(ans);
            else
            result.push_back(result.back()+ans);
        }
        return result;
    }
};