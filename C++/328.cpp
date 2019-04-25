__________________________________________________________________________________________________
sample 12 ms submission
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct Solution final {
    static ListNode* oddEvenList(ListNode* head) noexcept {
        if (!head) return nullptr;
        const auto even_head = head->next;
        auto odd = head;
        auto even = even_head;
        while (even && even->next) {
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        odd->next = even_head;
        return head;
    }
};

static const auto speedup = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
__________________________________________________________________________________________________
sample 9540 kb submission
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static const auto ___ = [](){
    std::cout.sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)  return NULL;
        ListNode* save = head;
        ListNode *curr = head,*next = head->next;
        if(next==NULL)  return curr;
        while(curr&&next&&next->next) {
            ListNode *temp = curr->next;
            curr->next = next->next;
            next->next = curr->next->next;
            curr->next->next = temp;
            curr = curr->next;
            next = next->next;
        }
        return head;
    }
};
__________________________________________________________________________________________________
