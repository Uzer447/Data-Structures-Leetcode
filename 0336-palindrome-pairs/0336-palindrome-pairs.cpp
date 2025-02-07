#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wordMap;
        set<vector<int>> resSet;
        int n = words.size();
        int emptyWordIndex = -1;
        for(int i = 0; i < n; ++i) {
            wordMap[words[i]] = i;
            if(words[i] == "") {
                emptyWordIndex = i;
            }
        }
        for(int i = 0; i < n; ++i) {
            string word = words[i];
            if(word == "") continue;
            string reversed_word = word;
            reverse(reversed_word.begin(), reversed_word.end());
            if(wordMap.count(reversed_word) && wordMap[reversed_word] != i) {
                resSet.insert({i, wordMap[reversed_word]});
            }
            int len = word.size();
            for(int j = 1; j < len; ++j) {
                string left = word.substr(0, j);
                string right = word.substr(j);
                if(isPalindrome(left)) {
                    string reversed_right = right;
                    reverse(reversed_right.begin(), reversed_right.end());
                    if(wordMap.count(reversed_right) && wordMap[reversed_right] != i) {
                        resSet.insert({wordMap[reversed_right], i});
                    }
                }
                if(isPalindrome(right)) {
                    string reversed_left = left;
                    reverse(reversed_left.begin(), reversed_left.end());
                    if(wordMap.count(reversed_left) && wordMap[reversed_left] != i) {
                        resSet.insert({i, wordMap[reversed_left]});
                    }
                }
            }
        }
        if(emptyWordIndex != -1) {
            for(int i = 0; i < n; ++i) {
                if(i != emptyWordIndex && isPalindrome(words[i])) {
                    resSet.insert({i, emptyWordIndex});
                    resSet.insert({emptyWordIndex, i});
                }
            }
        }
        vector<vector<int>> res(resSet.begin(), resSet.end());
        return res;
    }
private:
    bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
};