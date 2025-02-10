class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int length = 0;
        ListNode* ptr = head;
        while(ptr){
            ptr = ptr->next;
            length++;
        }

        short nodesPerPartition = length/k;
        short carry = length%k;

        ptr = head;

        ListNode* forw;
       
        vector<ListNode*> ans(k, nullptr);

        for(int i = 0 ; i < k && ptr; i++){
            ans[i] = ptr;
            for(int j = 1 ; j < nodesPerPartition; j++) ptr = ptr->next;
            if(carry != 0 && k < length){
                ptr = ptr->next;
                carry--;
            }
            forw = ptr->next;
            ptr->next = nullptr;
            ptr = forw;
        }
        return ans;
    }
};