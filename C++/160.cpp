__________________________________________________________________________________________________
36ms
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

static const auto s = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return NULL;
        
        int lenA = listLen(headA);
        int lenB = listLen(headB);
        
        if(lenA >= lenB){
            int dis = lenA - lenB;
            while(dis> 0){
                headA = headA->next;
                dis--;
            }
        }
        else{
            int dis = lenB - lenA;
            while(dis > 0){
                headB = headB->next;
                dis--;
            }
        }
        
        while(headA!=nullptr && headB!= nullptr){
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
    
    int listLen(ListNode *head){
        if(head == nullptr)
            return 0;
        
        int len = 0;
        while(head!=nullptr){
            len++;
            head = head->next;
        }
        return len;
    }
};
__________________________________________________________________________________________________
16508 kb
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getListLength(headA);
        int lenB = getListLength(headB);
        if(lenA > lenB){
            headA = goForward(lenA, lenB, headA);
        }
        else{
            headB = goForward(lenB, lenA, headB);
        }
        while(headA && headB){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
    
    int getListLength(ListNode *head){
        int len = 0;
        while(head){
            head = head->next;
            len++;
        }
        return len;
    }
    
    ListNode *goForward(int long_len, int short_len, ListNode *head){
        int delta = long_len - short_len;
        while(head && delta){
            head = head->next;
            delta--;
        }
        return head;
    }
};
__________________________________________________________________________________________________
