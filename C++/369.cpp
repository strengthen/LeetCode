__________________________________________________________________________________________________
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (!head) return head;
        ListNode *rev_head = reverse(head), *cur = rev_head, *pre = cur;
        int carry = 1;
        while (cur) {
            pre = cur;
            int t = cur->val + carry;
            cur->val = t % 10;
            carry = t / 10;
            if (carry == 0) break;
            cur = cur->next;
        }
        if (carry) pre->next = new ListNode(1);
        return reverse(rev_head);
    }
    ListNode* reverse(ListNode *head) {
        if (!head) return head;
        ListNode *dummy = new ListNode(-1), *cur = head;
        dummy->next = head;
        while (cur->next) {
            ListNode *t = cur->next;
            cur->next = t->next;
            t->next = dummy->next;
            dummy->next = t;
        }
        return dummy->next;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (!head) return head;
        int carry = helper(head);
        if (carry == 1) {
            ListNode *res = new ListNode(1);
            res->next = head;
            return res;
        }
        return head;
    }
    int helper(ListNode *node) {
        if (!node) return 1;
        int carry = helper(node->next);
        int sum = node->val + carry;
        node->val = sum % 10;
        return sum / 10;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode *cur = head, *right = NULL;
        while (cur) {
            if (cur->val != 9) right = cur;
            cur = cur->next;
        }
        if (!right) {
            right = new ListNode(0);
            right->next = head;
            head = right;
        }
        ++right->val;
        cur = right->next;
        while (cur) {
            cur->val = 0;
            cur = cur->next;
        }
        return head;
    }
};