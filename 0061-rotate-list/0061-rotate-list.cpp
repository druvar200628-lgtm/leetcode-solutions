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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == null)
        return head;
        node* last = head;
        int n = 1;
        while(last->next != null){
            n++;
            last=last->next;
        }
        k = k % n;
        if(k == 0)
            return head;
        int count = 1;
        int c = n-k;
        node* t = head;
        while(t != null){
            if(count == c)
                break;
            count++;
            t=t->next;
        }
        node* res = t->next;
        last->next = head;
        t->next=null;
    
    return res;
    }
};