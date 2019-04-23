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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* n = head->next;
        head->next = swapPairs(head->next->next);
        n->next = head;
        return n;
    }
};
__________________________________________________________________________________________________
4ms
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        while (pre->next && pre->next->next) {
            ListNode *t = pre->next->next;
            pre->next->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pre = t->next;
        }
        return dummy->next;
    }
};
__________________________________________________________________________________________________
8676 kb
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* first = head;
        ListNode* sec;
        
        while(first && first->next) {
            sec = first->next;
            first->next = sec->next;
            prev->next = sec;
            sec->next = first;
            prev = first;
            first = first->next;
        }
        
        head = dummy->next;
        return head;
    }
};
__________________________________________________________________________________________________
8696 kb
class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if(head == nullptr){
                return nullptr;
            }
            ListNode* cnt = nullptr;
            if(head->next == nullptr){
                return head;
            }
            else{
                cnt = swapPairs(head->next->next);
            }
            ListNode* secondNode = head->next;
            secondNode->next = head;
            head->next = cnt;
            return secondNode;
        }
};
__________________________________________________________________________________________________
8708 kb 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *res = new ListNode(0);
        ListNode *tmp = res;
        while(head && head -> next) {
            ListNode *new_head = head->next->next;
            tmp->next = head->next;
            tmp = tmp->next;
            tmp->next = head;
            tmp = tmp->next;
            head = new_head;
        }
        tmp->next = head;
        return res->next;
    }
};
__________________________________________________________________________________________________
