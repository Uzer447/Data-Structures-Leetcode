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
void insertCopyInBetween(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* nextElement = temp->next;
        Node* copy = new Node(temp->val);  
        copy->next = nextElement;  
        temp->next = copy;         
        temp = nextElement;         
    }
}
void connectRandomPointers(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* copyNode = temp->next;    
        if(temp->random){   
            copyNode->random = temp->random->next; 
        }
        else{
            copyNode->random = NULL;   
        }
        temp = temp->next->next;   
    }
}
Node* getDeepCopyList(Node* head){
    Node* temp = head;
    Node* dummyNode = new Node(-1);   
    Node* res = dummyNode;             
    while(temp != NULL){
        res->next = temp->next;
        res = res->next;
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;   
}
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
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