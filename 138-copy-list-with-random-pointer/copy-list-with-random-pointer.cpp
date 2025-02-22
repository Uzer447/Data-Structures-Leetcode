/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* newhead=new Node(head->val);
        Node* temp2=newhead;
        map<Node*,Node*> mp;
        Node* temp=head->next;
        mp[head]=newhead;
        while(temp!=NULL)
        {   
            Node* newNode=new Node(temp->val);
            temp2->next=newNode;
            mp[temp]=newNode;
            temp2=temp2->next;
            temp=temp->next;
        }
        temp2=newhead;
        temp=head;
        while(temp2!=NULL)
        {
            temp2->random=mp[temp->random];
            temp2=temp2->next;
            temp=temp->next;
        }
        return newhead;
    }
};