struct Node {
    Node* chars[26];
    int ps;

    bool isExists(char ch) {
        return chars[ch-'a'] != NULL;
    }

    void setCharacter(char ch, Node* node) {
        chars[ch-'a'] = node;
    }

    Node* getCharacter(char ch) {
        return chars[ch-'a'];
    }

    void updateSum(int sum) {
        ps += sum;
    }
};

class MapSum {
private:
    Node* root;
    unordered_map<string, int> map;

public:
    MapSum() {
        root = new Node();
        root->ps = 0;
    }
    
    void insert(string key, int val) {
        int sum = val;
        if(map.find(key) != map.end()) {
            sum -= map[key];
        }

        map[key] = val;
        
        Node* currNode = root;
        for(int i=0 ; i<key.length() ; i++) {
            if(currNode->isExists(key[i]) == false) {
                currNode->setCharacter(key[i], new Node());
            }
            currNode = currNode->getCharacter(key[i]);
            currNode->updateSum(sum);
        }
    }
    
    int sum(string prefix) {
        Node* currNode = root;

        for(int i=0 ; i<prefix.length() ; i++){
            if(currNode->isExists(prefix[i]) == true) {
                currNode = currNode->getCharacter(prefix[i]);
            }
            else return 0;
        }

        return currNode->ps;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */