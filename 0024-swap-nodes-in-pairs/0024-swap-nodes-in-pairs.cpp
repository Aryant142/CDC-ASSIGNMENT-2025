class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = NULL;

        while (first && sec) {
            ListNode* third = sec->next;

            sec->next = first;
            first->next = third;

            if (prev) {
                prev->next = sec;
            } else {
                head = sec; // New head after first swap
            }

            prev = first;
            first = third;
            sec = (first ? first->next : NULL);
        }

        return head;
    }
};
