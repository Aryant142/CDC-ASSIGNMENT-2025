class Solution {
public:
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* prev = nullptr;
    //     ListNode* curr = head;

    //     while (curr) {
    //         ListNode* next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //     }
    //     return prev;
    // }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverseList(l1);
        // l2 = reverseList(l2);
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        // Reverse the sum to restore forward order
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result; // ✅ Only reverse once
    }
};


