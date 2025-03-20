#include <bits/stdc++.h>
using namespace std;
 
struct TrieNode {
    bool end;
    TrieNode* children[26];
    TrieNode(): end(false) {
        for(int i=0; i<26; i++) children[i] = nullptr;
    }
};
 
class StreamChecker {
    TrieNode* root;
    deque<char> stream;
    int maxLen;
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        maxLen = 0;
        for(auto &w: words){
            maxLen = max(maxLen, (int)w.size());
            TrieNode* cur = root;
            for(int i = w.size()-1; i>=0; i--){
                int index = w[i] - 'a';
                if(!cur->children[index]) cur->children[index] = new TrieNode();
                cur = cur->children[index];
            }
            cur->end = true;
        }
    }
    
    bool query(char letter) {
        stream.push_front(letter);
        if(stream.size() > maxLen) stream.pop_back();
        TrieNode* cur = root;
        for(auto c : stream){
            int idx = c - 'a';
            if(!cur->children[idx]) return false;
            cur = cur->children[idx];
            if(cur->end) return true;
        }
        return false;
    }
};