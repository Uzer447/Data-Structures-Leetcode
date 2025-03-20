#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int val;
    vector<Node*> forward;
    Node(int v, int level): val(v), forward(level, nullptr) {}
};
 
class Skiplist {
    int MAX_LEVEL = 16;
    double P = 0.5;
    int level = 1;
    Node* head = new Node(-1, MAX_LEVEL);
public:
    Skiplist() { srand((unsigned)time(0)); }
    
    int randomLevel(){
        int lvl = 1;
        while(((double)rand() / RAND_MAX) < P && lvl < MAX_LEVEL) lvl++;
        return lvl;
    }
    
    bool search(int target) {
        Node* curr = head;
        for(int i = level - 1; i >= 0; i--){
            while(curr->forward[i] && curr->forward[i]->val < target)
                curr = curr->forward[i];
        }
        curr = curr->forward[0];
        return curr && curr->val == target;
    }
    
    void add(int num) {
        vector<Node*> update(MAX_LEVEL, nullptr);
        Node* curr = head;
        for(int i = level - 1; i >= 0; i--){
            while(curr->forward[i] && curr->forward[i]->val < num)
                curr = curr->forward[i];
            update[i] = curr;
        }
        int lvl = randomLevel();
        if(lvl > level){
            for(int i = level; i < lvl; i++) update[i] = head;
            level = lvl;
        }
        Node* node = new Node(num, lvl);
        for(int i = 0; i < lvl; i++){
            node->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = node;
        }
    }
    
    bool erase(int num) {
        vector<Node*> update(MAX_LEVEL, nullptr);
        Node* curr = head;
        for(int i = level - 1; i >= 0; i--){
            while(curr->forward[i] && curr->forward[i]->val < num)
                curr = curr->forward[i];
            update[i] = curr;
        }
        curr = curr->forward[0];
        if(!curr || curr->val != num) return false;
        for(int i = 0; i < level; i++){
            if(update[i]->forward[i] != curr) break;
            update[i]->forward[i] = curr->forward[i];
        }
        delete curr;
        while(level > 1 && head->forward[level-1] == nullptr) level--;
        return true;
    }
};