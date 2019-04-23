__________________________________________________________________________________________________
12ms
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
__________________________________________________________________________________________________
8980 kb
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        if (p == nullptr) return head;
        
        ListNode* q = p->next;
        unordered_set<int> s;

        while (q != nullptr) {
            if (q->val == p->val) {
                q = q->next;
                p->next = q;
            }
            else {
                p = q;
                q = q->next;
            }
        }
        return head;
    }
};
__________________________________________________________________________________________________
