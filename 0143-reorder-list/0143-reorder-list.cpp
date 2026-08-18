class Solution {
public:

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;

        while(head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    void merge(ListNode* l1, ListNode* l2) {
        while(l1 && l2) {

            ListNode* next1 = l1->next;
            ListNode* next2 = l2->next;

            l1->next = l2;

            if(next1 == NULL)
                break;

            l2->next = next1;

            l1 = next1;
            l2 = next2;
        }
    }

    void reorderList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split into two lists
        ListNode* l1 = head;
        ListNode* l2 = slow->next;

        slow->next = NULL;

        // Reverse second half
        l2 = reverse(l2);

        // Merge alternatively
        merge(l1, l2);
    }
};