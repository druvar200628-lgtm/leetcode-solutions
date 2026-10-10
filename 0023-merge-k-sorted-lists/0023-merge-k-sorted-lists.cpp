class Node{
    public:
    int val, row, col;
    Node(int v, int i, int j){
        val = v;
        row = i;
        col = j;
    }
};

struct cmp{
    bool operator()(const Node &a, const Node &b){
        return a.val > b.val; // min-heap
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<Node, vector<Node>, cmp> pq;

       
        for(int i = 0; i < n; i++){
            if(lists[i]){
                pq.push({lists[i]->val, i, 0});
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(!pq.empty()){
            Node top = pq.top();
            pq.pop();

            int r = top.row;

            
            curr->next = lists[r];
            curr = curr->next;
            lists[r] = lists[r]->next; 

           
            if(lists[r]){
                pq.push({lists[r]->val, r, 0});
            }
        }
        return dummy->next;
    }
};
