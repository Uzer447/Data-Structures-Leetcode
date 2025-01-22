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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* merge2(ListNode* head1,ListNode* head2)
    {
        ListNode* dNode=new ListNode(-1);
        ListNode* temp=dNode;
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val < head2->val)
            {
                temp->next=head1;
                temp=head1;
                head1=head1->next;
            }
            else
            {
                temp->next=head2;
                temp=head2;
                head2=head2->next;
            }
        }
        if(head1) temp->next=head1;
        else temp->next=head2;
        return dNode->next;
    }
    ListNode* mergesort(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
        return head;
        ListNode* mid=middleNode(head);
        ListNode* leftHead=head;
        ListNode* rightHead=mid->next;
        mid->next=NULL;
        leftHead=mergesort(leftHead);
        rightHead=mergesort(rightHead);
        return merge2(leftHead,rightHead);
    }
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};