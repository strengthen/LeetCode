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
static const auto speedup = []() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        bool findCycle = false;
        while(slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) 
            {
                findCycle = true;
                break;
            }
        }
        if(!findCycle) return nullptr;
        
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
__________________________________________________________________________________________________
9548 kb
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
    ListNode *detectCycle(ListNode *head) {
        bool cycle = 0;
        ListNode *runner1 = head;
        ListNode *runner2 = head;
        if(head == NULL) return {};
        while(runner2->next != NULL && runner2->next->next != NULL) {
            runner1 = runner1->next;
            runner2 = runner2->next->next;
            if(runner1 == runner2) {
                cycle = 1;
                break;
            }
        }
        if(cycle) {
            runner1 = head;
            while(runner1 != runner2) {
                runner1 = runner1->next;
                runner2 = runner2->next;
            }
            return runner1;
        }
        return {};
    }
};
__________________________________________________________________________________________________
