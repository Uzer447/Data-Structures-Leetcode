class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ind;
        int i=0;
        for(auto word:words)
        {
            if(word.find(x)!=string::npos)
            ind.push_back(i);
            i++;
        }
        return ind;
    }
};
