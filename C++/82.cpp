__________________________________________________________________________________________________
8ms
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
        if (head == nullptr) return nullptr;

        auto pprev = &head;
        auto prev = head;
        auto next = head->next;
        int count = 1;

        while (next) {
            if (next->val != prev->val) {
                if (count > 1) {
                    *pprev = next;
                } else {
                    pprev = &prev->next;
                }
                prev = next;
                count = 1;
            } else {
                ++count;
            }
            next = next->next;
        }
        if (count > 1) {
            *pprev = nullptr;
        }

        return head;
    }
};
__________________________________________________________________________________________________
8832 kb
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
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* curr = dummy;
        ListNode *p1 = dummy, *p2 = head;
        
        while (p1 && p2) {
            if (p2 -> next && p2 -> val == p2 -> next -> val) {
                int duplicate = p2 -> val;
                while (p2 && p2 -> val == duplicate) {
                    p2 = p2 -> next;
                }
                p1 -> next = p2;
            } else {
                p1 = p1 -> next;
                p2 = p2 -> next;
            }
        }
        
        return dummy -> next;
    }
};
__________________________________________________________________________________________________
