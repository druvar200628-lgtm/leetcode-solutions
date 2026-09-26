class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL){
            return NULL;
        }
        if(left == right){
            return head;
        }
        ListNode* t = head;
        ListNode* before = NULL;
        int pos = 1;
        while(t != NULL){
            if(pos < left){
                before = t;
                t = t->next;
                pos++;
                continue;
            }
            ListNode* cur = t;
            ListNode* prev = NULL;
            int times = right - left + 1;
            while(times--){
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            t->next = cur;
            if(before){
                before->next = prev;
                return head;
            }
            return prev;
        }
        return head;     
        
    }
};