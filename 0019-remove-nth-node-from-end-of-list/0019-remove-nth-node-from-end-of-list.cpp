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
    void solve(ListNode* head,ListNode* prv, int &cnt, int n){
        if(head == NULL) return ;

        solve(head->next,head,cnt,n);
        cnt++;

        if(cnt == n){
            prv->next = head->next;
            head->next = NULL;    
        }
        
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int cnt = 0;
        int count = 0;
        ListNode* temp = head;

        while(temp){
            count++;
            temp = temp->next;
        }

        if(count == n) return head->next;
        solve(head,NULL,cnt,n);


        return head;
    }
};