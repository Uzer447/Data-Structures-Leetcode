/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverselist(ListNode* head)
    {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL)
        {
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    ListNode* getKthNode(ListNode* head, int k)
    {
        ListNode* temp=head;
        k--;
        while(temp!=NULL && k>0)
        {
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevlast=NULL;
        while(temp!=NULL)
        {
            ListNode* kthNode=getKthNode(temp,k);
            if(kthNode==NULL)
            {
                if(prevlast)
                prevlast->next=temp;
                break;
            }
            ListNode* nextnode=kthNode->next;
            kthNode->next=NULL;
            reverselist(temp);
            if(temp==head)
            {
                head=kthNode;
            }
            else
            {
                prevlast->next=kthNode;
            }
            prevlast=temp;
            temp=nextnode;
        }
        return head;
    }
};