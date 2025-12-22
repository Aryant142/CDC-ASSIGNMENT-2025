class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> m;

        // Step 1: Create copy of nodes (only next pointers)
        Node* newnode = new Node(head->val);
        Node* oldtemp = head->next;
        Node* newtemp = newnode;
        m[head] = newnode;

        while (oldtemp != NULL) {
            Node* copynode = new Node(oldtemp->val);
            m[oldtemp] = copynode;
            newtemp->next = copynode;

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        // Step 2: Assign random pointers
        oldtemp = head;
        newtemp = newnode;
        while (oldtemp != NULL) {
            if (oldtemp->random != NULL)
                newtemp->random = m[oldtemp->random];
            else
                newtemp->random = NULL;

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        return newnode;
    }
};
