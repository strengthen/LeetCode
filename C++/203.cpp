__________________________________________________________________________________________________
sample 24 ms submission
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
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    ListNode* removeElements(ListNode* head, int val) {
        while(head != nullptr and head->val == val)
        {
            auto hn = head->next;
            //delete head;
            head = hn;
        }
        
        if(head == nullptr)
        {
            return nullptr;
        }
        
        auto temp = head;
        
        while(head->next != nullptr)
        {
            while(head->next != nullptr and (head->next->val != val))
            {
                head = head->next;
            }
            
            if(head->next == nullptr)
            {
                break;
            }
            
            auto nextnext = head->next->next;
            //delete head->next;
            head->next = nextnext;
        }
        return temp;
    }
};
__________________________________________________________________________________________________
sample 10968 kb submission
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static const auto speedup =[]() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        ListNode* dummy = new ListNode(-1), *itr, *prev;
        dummy -> next = head;
        prev = dummy;
        itr = prev -> next;
        while(itr) {
            if(itr -> val == val) {
                prev -> next = itr -> next;
                itr = prev -> next;
            }
            else {
                prev = prev -> next;
                itr = prev -> next;
            }
        }
        
        return dummy -> next;
    }
};
__________________________________________________________________________________________________
