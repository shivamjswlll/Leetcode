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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* head = NULL;
        ListNode* tmp = NULL;

        if(temp1 == NULL) return temp2;
        if(temp2 == NULL) return temp1;

        while(temp1 && temp2){
            if(temp1->val <= temp2->val){
                if(head == NULL){
                    head = temp1;
                    temp1 = temp1->next;
                    tmp = head;
                }else{
                    tmp->next = temp1;
                    tmp = temp1;
                    temp1 = temp1->next;
                }
            }
            else{
                if(head == NULL){
                    head = temp2;
                    temp2 = temp2->next;
                    tmp = head;
                }else{
                    tmp->next = temp2;
                    tmp = temp2;
                    temp2 = temp2->next;
                }
            }
        }
        if(temp1 == NULL && temp2 != NULL){
            tmp->next = temp2;
        }
        if(temp2 == NULL && temp1 != NULL){
            tmp->next = temp1;
        }

        return head;
    }
};