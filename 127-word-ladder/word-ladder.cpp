class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endWord) return steps;
            for(int i=0;i<word.size();i++){
                for(int j='a';j<='z';j++){
                    string newWord=word;
                    newWord[i]=j;
                    if(newWord==word) continue;
                    if(st.count(newWord)==1){
                        q.push({newWord,steps+1});
                        st.erase(newWord);
                    }
                }
            }
        }
        return 0;
    }
};