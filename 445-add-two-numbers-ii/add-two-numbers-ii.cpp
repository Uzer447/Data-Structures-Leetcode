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

    ListNode* reverseList(ListNode * head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
        
        int carry=0;
        int val;
        ListNode* dummy=new ListNode(0);
        ListNode *start=dummy;
        while(l1 || l2){
            int x= (l1? l1->val:0);
            int y= (l2? l2->val:0);
            int total= x+y+carry;
            carry=total/10;
            int digit=total%10;

            ListNode* node=new ListNode(digit);
            dummy->next=node;
            dummy=node;
            if(l1){
                l1=l1->next;
            }
            if(l2){
                l2=l2->next;
            }
            
        }
        if(carry){
            ListNode* node=new ListNode(carry);
            dummy->next=node;
            dummy=node;
        }

        return reverseList(start->next);
    }
};