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

#define null NULL
#define node ListNode
#define data val
#define ed endl

void reverse(node* head,int times){
    node* cur = head;
    node* prev = null;
    while(times--){
        node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return;
}
    ListNode* swapPairs(ListNode* head) {
        if(head == null){
            return head;
        }
        int size = 2;
        node* left = head;
        node* res = null;
        node* right;
        node* prevleft = null;
        while(true){
            right = left;
            for(int i = 0 ; i < size-1 ; i++ ){
                if(right == null)
                break;
                right = right->next;
            }
            if(right){
                node* nextleft = right->next;
                reverse(left,size);
                if(prevleft)
                    prevleft->next = right;
                prevleft = left;

                if(res == null)
                    res = right;

                left = nextleft;                  
            }
            else{
                if(prevleft){
                    prevleft->next = left;
                }
                if(res == null){
                    res = left;
                }
                break;
            }

        }
         
        return res;
        
    }
};