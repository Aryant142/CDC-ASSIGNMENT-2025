class LRUCache {
public:

    class Node {
    public:
        int key, val;
        Node* next;
        Node* prev;

        Node(int k, int v) {
            this->key = k;
            this->val = v;
            this->next = NULL;
            this->prev = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int limit;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {
        if (m.find(key) == m.end())
            return -1;

        Node* node = m[key];
        int value = node->val;

        m.erase(key);
        deleteNode(node);

        addNode(node);
        m[key] = node;

        return value;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* oldNode = m[key];
            m.erase(key);
            deleteNode(oldNode);
        }

        if (m.size() == limit) {
            Node* least = tail->prev;
            m.erase(least->key);
            deleteNode(least);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};
