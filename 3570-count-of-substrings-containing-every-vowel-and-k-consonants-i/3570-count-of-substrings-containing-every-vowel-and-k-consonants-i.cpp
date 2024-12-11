class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        int cnt=0;
        for (int i = 0; i < n; i++) {
            vector<int> hash(6,0);
            for (int j = i; j < n; j++) {
                if (word[j] == 'a')
                    hash[0]++;
                else if (word[j] == 'e')
                    hash[1]++;
                else if (word[j] == 'i')
                    hash[2]++;
                else if (word[j] == 'o')
                    hash[3]++;
                else if (word[j] == 'u')
                    hash[4]++;
                else
                    hash[5]++;
                if(hash[0]>0 && hash[1]>0 && hash[2]>0 && hash[3]>0 && hash[4]>0 && hash[5]==k)
                cnt++;
            }
        }
        return cnt;
    }
};