__________________________________________________________________________________________________
sample 0 ms submission
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
    int getDecimalValue(ListNode* head) {
        int ans=0;
        int i=0;
        ListNode *prev=NULL,*curr=head,*next=head;
        while(next!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
        }
        while(prev!=NULL)
        {
            ans+=((prev->val)*pow(2,i));
            i++;
            prev=prev->next;
        }
        return ans;
    }
};
__________________________________________________________________________________________________
4ms
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ret = 0;
        while(head)
        {
            ret <<= 1;
            ret |= head->val;
            head = head->next;
        }
        return ret;
    }
};
__________________________________________________________________________________________________
