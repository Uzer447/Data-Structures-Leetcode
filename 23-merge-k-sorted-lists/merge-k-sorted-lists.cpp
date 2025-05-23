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
 class Compare {
public:
    bool operator()(ListNode* a, ListNode* b)
    {
        if (a->val > b->val) {
            return true;
        }
        return false;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>, Compare> pq;
        for(auto it:lists)
        {
            if(it!=NULL)
            {
                pq.push(it);
            }
        }
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        while(!pq.empty())
        {
            ListNode* node=pq.top();
            pq.pop();
            temp->next=node;
            temp=temp->next;
            if(node->next!=NULL)
            {
                pq.push(node->next);
            }
        }
        return dummy->next;
    }
};