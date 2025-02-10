struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
};


class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    int search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return INT_MAX;
            }
            node = node->get(word[i]);
            if(node->isEnd()) return i;
        }
        return INT_MAX;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for(auto it:dictionary) trie.insert(it);
        vector<string> words;
        string temp="";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' '){
                words.push_back(temp);
                temp="";
            }else temp.push_back(sentence[i]);
        }
        words.push_back(temp);
        
        string ans="";
        for(auto it:words){
            int ind = trie.search(it);
            if(ind==INT_MAX) ans+=it;
            else {
                string str=it.substr(0,ind+1);
                ans+=str;
            }
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};