__________________________________________________________________________________________________
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node(insertVal, NULL);
            head->next = head;
            return head;
        }
        Node *pre = head, *cur = pre->next;
        while (cur != head) {
            if (pre->val <= insertVal && cur->val >= insertVal) break;
            if (pre->val > cur->val && (pre->val <= insertVal || cur->val >= insertVal)) break;
            pre = cur;
            cur = cur->next;
        }
        pre->next = new Node(insertVal, cur);
        return head;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
