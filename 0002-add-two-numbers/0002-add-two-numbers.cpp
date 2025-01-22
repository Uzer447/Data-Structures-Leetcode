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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* num1=l1;
        ListNode* num2=l2;
        int sum=num1->val+num2->val+carry;
           if(sum>10)
            {
                carry=1;
                sum=sum%10;
            }
            else if(sum==10)
            {
                carry=1;
                sum=0;
            }
            else
            {
                carry=0;
            }
            ListNode* ans=new ListNode(sum);
            num1=num1->next;
            num2=num2->next;
            ListNode* temp=ans;
        while(num1!=NULL && num2!=NULL)
        {
            sum=num1->val+num2->val+carry;
            if(sum>10)
            {
                carry=1;
                sum=sum%10;
            }
            else if(sum==10)
            {
                carry=1;
                sum=0;
            }
            else
            {
                carry=0;
            }
            ListNode* temp1=new ListNode(sum);
            ans->next=temp1;
            ans=ans->next;
            num1=num1->next;
            num2=num2->next;
        }
        while(num1!=NULL)
        {
            sum=num1->val+carry;
            if(sum>10)
            {
                carry=1;
                sum=sum%10;
            }
            else if(sum==10)
            {
                carry=1;
                sum=0;
            }
            else
            {
                carry=0;
            }
            ListNode* temp1=new ListNode(sum);
            ans->next=temp1;
            ans=ans->next;
            num1=num1->next;
        }
        while(num2!=NULL)
        {
            sum=num2->val+carry;
            if(sum>10)
            {
                carry=1;
                sum=sum%10;
            }
            else if(sum==10)
            {
                carry=1;
                sum=0;
            }
            else
            {
                carry=0;
            }
            ListNode* temp1=new ListNode(sum);
            ans->next=temp1;
            ans=ans->next;
            num2=num2->next;
        }
        if(carry!=0)
        {
            ListNode* temp1=new ListNode(carry);
            ans->next=temp1;
            ans=ans->next;
        }
        return temp;
    }
};