class AllOne {
    struct Node {
        int count;
        unordered_set<string> keys;
        Node *prev, *next;
        Node(int c) : count(c), prev(nullptr), next(nullptr) {}
    };
    unordered_map<string, Node*> key2node;
    Node *head, *tail;
    void insertAfter(Node* node, Node* newNode) {
        newNode->prev = node;
        newNode->next = node->next;
        if (node->next) node->next->prev = newNode;
        else tail = newNode;
        node->next = newNode;
    }
    void insertBefore(Node* node, Node* newNode) {
        newNode->next = node;
        newNode->prev = node->prev;
        if (node->prev) node->prev->next = newNode;
        else head = newNode;
        node->prev = newNode;
    }
    void insertAtHead(Node* node) {
        node->prev = nullptr;
        node->next = head;
        if (head) head->prev = node;
        else tail = node;
        head = node;
    }
    void removeNode(Node* node) {
        if (node->prev) node->prev->next = node->next;
        else head = node->next;
        if (node->next) node->next->prev = node->prev;
        else tail = node->prev;
        delete node;
    }
public:
    AllOne() {
        head = nullptr;
        tail = nullptr;
    }

    void inc(string key) {
        if (key2node.find(key) == key2node.end()) {
            if (!head || head->count > 1) {
                Node* node = new Node(1);
                node->keys.insert(key);
                insertAtHead(node);
            } else {
                head->keys.insert(key);
            }
            key2node[key] = head;
        } else {
            Node* currNode = key2node[key];
            int currCount = currNode->count;
            Node* nextNode = currNode->next;
            currNode->keys.erase(key);
            if (nextNode && nextNode->count == currCount + 1) {
                nextNode->keys.insert(key);
            } else {
                Node* newNode = new Node(currCount + 1);
                newNode->keys.insert(key);
                insertAfter(currNode, newNode);
                nextNode = newNode;
            }
            key2node[key] = nextNode;
            if (currNode->keys.empty()) {
                removeNode(currNode);
            }
        }
    }

    void dec(string key) {
        auto it = key2node.find(key);
        if (it == key2node.end()) return;
        Node* currNode = it->second;
        int currCount = currNode->count;
        currNode->keys.erase(key);
        if (currCount == 1) {
            key2node.erase(it);
        } else {
            Node* prevNode = currNode->prev;
            if (prevNode && prevNode->count == currCount -1) {
                prevNode->keys.insert(key);
            } else {
                Node* newNode = new Node(currCount -1);
                newNode->keys.insert(key);
                insertBefore(currNode, newNode);
                prevNode = newNode;
            }
            key2node[key] = prevNode;
        }
        if (currNode->keys.empty()) {
            removeNode(currNode);
        }
    }

    string getMaxKey() {
        return tail && !tail->keys.empty() ? *(tail->keys.begin()) : "";
    }

    string getMinKey() {
        return head && !head->keys.empty() ? *(head->keys.begin()) : "";
    }
};