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
    ListNode* reverse(ListNode* tmp,size_t* len){
        ListNode dummy(-1);
        auto head = &dummy;
        size_t count = 0;
        while(tmp){
            auto next = tmp->next;
            tmp->next = head->next;
            head->next = tmp;
            tmp = next;
            count++;
        }
        if(len!=nullptr){
           *len = count; 
        }
        return head->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        size_t len_l1, len_l2;
        l1 = reverse(l1,&len_l1);
        l2 = reverse(l2,&len_l2);
        if(len_l1<len_l2){
            swap(l1,l2);
        }
        int count = 0;
        ListNode* head = l1;
        ListNode* last = nullptr;
        while(l2){
            int result = l2->val + l1->val + count;
            count = result / 10;
            l1->val = result % 10;
            last = l1;
            l2 = l2->next;
            l1 = l1->next;
        }
        while(l1){
            int result = l1->val + count;
            count = result /10;
            l1->val = result % 10;
            last = l1;
            l1 = l1->next;
        }
        if(count){
            last->next = new ListNode(count);
            count = 0;
            last = last ->next;
        }
        return reverse(head,nullptr);
        
    }
};
__________________________________________________________________________________________________
sample 10328 kb submission
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head) {
        ListNode* next = nullptr;
        while(head) {
            // ListNode* tail = head->next;
            // head->next = next;
            // next = head;
            // head = tail;
            std::swap(head->next, next);
            std::swap(next, head);
        }
        return next;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        ListNode  l(0);
        ListNode* n = &l;

        int carry = 0;
        while(l1 || l2 || carry > 0) {
            int dig = carry;
            if(l1) {
                dig += l1->val;
                l1   = l1->next;
            }
            if(l2) {
                dig += l2->val;
                l2   = l2->next;
            }
            carry = dig / 10;
            
            n->next = new ListNode(dig % 10);
            n = n->next;
        }
        
        return reverse(l.next);
    }
};

static int x {[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}()};
__________________________________________________________________________________________________
