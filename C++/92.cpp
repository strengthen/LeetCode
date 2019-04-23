__________________________________________________________________________________________________
4ms
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
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m==n)
            return head;
        
        ListNode* savehead = head;
        
        int count = 1;
        ListNode *start, *prestart, *end, *prev = NULL, *last=NULL;
        
        
        while (count != m) {
            prev = head;
            head=head->next;
            count++;
        }
        
        start = head;
        prestart = prev;
        
        while(count <= n) {
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
            count++;            
        }
        
        if(prestart)
            prestart->next = prev;
        
        start->next = head;
        
        if(m==1)
            return prev;
        
        return savehead;
        
    }
};
__________________________________________________________________________________________________
8612 kb
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
   ListNode* reverseBetween(ListNode* head, int m, int n) {
       ListNode *dummy = new ListNode(0), *pre = dummy;
       dummy -> next = head;
       for (int i = 1; i < m; i++) {
           pre = pre -> next;
       }
       ListNode* cur = pre -> next;
       for (int i = 0; i < n - m; i++) {
           ListNode* move = cur -> next;
           cur -> next = move -> next;
           move -> next = pre -> next;
           pre -> next = move;
       }
       return dummy -> next;
   }
};
__________________________________________________________________________________________________
