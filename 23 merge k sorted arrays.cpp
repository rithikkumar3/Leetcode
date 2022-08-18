//heaps
//priority_queue
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(ListNode* list:lists){
            while(list){
                pq.push(list->val);
                list=list->next;
            }
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        while(!pq.empty()){
            int temp=pq.top();
            pq.pop();
            head->next=new ListNode(temp);
            head=head->next;
        }
        return dummy->next;
    }
};