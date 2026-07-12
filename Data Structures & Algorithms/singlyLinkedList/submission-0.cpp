class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val) {
        this->val = val;
        this->next = nullptr;
    }
    ListNode(int val, ListNode* next) {
        this->val = val;
        this->next = next;
    }
};

class LinkedList {
    ListNode* head;
    ListNode* tail;
public:
    LinkedList() {
        head = new ListNode(-1);
        tail = head;
    }

    int get(int index) {
        ListNode *cur = head->next;
        int i = 0;
        while (cur != nullptr) {
            if (i == index) {
                return cur->val;
            }
            ++i;
            cur = cur->next;
        }
        return -1;
    }

    void insertHead(int val) {
        ListNode *node = new ListNode(val);
        node->next = head->next;
        head->next = node;
        if (node->next == nullptr) {
            tail = node;
        }
    }
    
    void insertTail(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    bool remove(int index) {
        int i = 0;
        ListNode* cur = head;
        while (i < index && cur != nullptr) {
            i++;
            cur = cur->next;
        }
        if (cur != nullptr && cur->next != nullptr) {
            if (cur->next == tail) {
                tail = cur;
            }
            ListNode *todelete = cur->next;
            cur->next = cur->next->next;
            delete todelete;
            return true;
        }
        return false;
    }

    vector<int> getValues() {
        vector<int> res;
        ListNode *cur = head->next;
        while (cur != nullptr) {
            res.push_back(cur->val);
            cur = cur->next;
        }
        return res;
    }
};
