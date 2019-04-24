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
    Solution() {
      std::ios::sync_with_stdio(false);
      std::cin.tie(0); std::cout.tie(0);
    }
    bool hasCycle(ListNode *head) {
      if (head == nullptr || head->next == nullptr) {
        return false;
      }
      ListNode* s = head;
      ListNode* f = head->next;
      while (s != f) {
        if (s == nullptr || f == nullptr || f->next == nullptr) {
          return false;
        }
        s = s->next;
        f = f->next->next;
      }
      return true;
    }
};
__________________________________________________________________________________________________
9496 kb
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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return false;
        ListNode *slow=head, *fast =head;
        while(slow!=NULL && fast !=NULL){
            slow = slow->next;
            if(fast->next && fast->next->next)
                fast = fast->next->next;
            else
                return false;
            if(fast == slow)
                return true;
        }
        return false;
    }
};
__________________________________________________________________________________________________
