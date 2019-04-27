__________________________________________________________________________________________________
sample 36 ms submission
class MyLinkedList {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int v): val(v), next(NULL), prev(NULL) {}
    };
    ListNode *dummy;
    int count;
    ListNode* foundNodeAtIndex(int index) {
        ListNode* cur;
        if (index > count / 2) {
            // from back
            int i = count - index - 1;
            cur = dummy->prev;
            while (i > 0) {
                --i;
                cur = cur->prev;
            }
        } else {
            // from front
            int i = 0;
            cur = dummy->next;
            while (i < index) {
                ++i;
                cur = cur->next;
            }
        }
        return cur;
    }
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        dummy = new ListNode(-1);
        count = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= count) return -1;
        if (index == 0) return dummy->next->val;
        if (index == count-1) return dummy->prev->val;
        ListNode* cur = foundNodeAtIndex(index);
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* head = dummy->next;
        ListNode* node = new ListNode(val);
        if (!head) {
            node->next = dummy;
            dummy->next = node;
            node->prev = dummy;
            dummy->prev = node;
        } else {
            node->next = head;
            node->prev = dummy;
            dummy->next = node;
            head->prev = node;
        }
        ++count;

    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* tail = dummy->prev;
        if (!tail) {
            ListNode* node = new ListNode(val);
            node->next = dummy;
            dummy->next = node;
            node->prev = dummy;
            dummy->prev = node;
        } else {
            ListNode* node = new ListNode(val);
            tail->next = node;
            node->prev = tail;
            node->next = dummy;
            dummy->prev = node;
        }
        ++count;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > count) return;
        else if (index == count) addAtTail(val);
        else if (index <= 0) addAtHead(val);
        else {
            ListNode* cur = foundNodeAtIndex(index);
            ListNode* node = new ListNode(val);
            node->next = cur;
            node->prev = cur->prev;
            node->next->prev = node;
            node->prev->next = node;
            ++count;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= count) return;
        ListNode* cur = foundNodeAtIndex(index);
        ListNode* prev = cur->prev;
        prev->next = cur->next;
        prev->next->prev = prev;
        delete cur;
        --count;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

auto ___ = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
__________________________________________________________________________________________________
sample 19048 kb submission
class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= value.size())
            return -1;
        return value[index];
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        value.insert(value.begin(), val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        value.push_back(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index <= value.size())
            value.insert(value.begin()+index, val);
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < value.size())
        value.erase(value.begin()+index);
    }
private:
    vector<int> value;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
__________________________________________________________________________________________________
