__________________________________________________________________________________________________
sample 4 ms submission
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
    ListNode* middleNode(ListNode* head) {
        if(!head) return nullptr;
        int count = 0;
        auto node = head;
        while(node) {
            node = node->next;
            ++count;
        }
        node = head;
        for(int i=0; i<count/2; ++i)
            node = node->next;
        return node;
    }
};
__________________________________________________________________________________________________
sample 8220 kb submission
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
    ListNode* middleNode(ListNode* head)
    {
        int count = 0;
        ListNode * curr = head;
        while(curr)
        {
            ++count;
            curr = curr->next;
        }
        
        count >>= 1;
        curr = head;
        while(count--)
            curr = curr->next;
        
        return curr;
    }
};
__________________________________________________________________________________________________
