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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur = cur->next = l1;
                l1 = l1->next;
            } else {
                cur = cur->next = l2;
                l2 = l2->next;
            }
        }

        if (l1) cur->next = l1;
        if (l2) cur->next = l2;

        return dummy->next;
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return NULL;
       ListNode *ans=NULL, *p;
       if (!l1 || (l2 && l2->val <= l1->val)) {
           ans = l2;
           l2 = l2->next;
       } else {
           ans = l1;
           l1 = l1->next;
       }
       p = ans;
       while(l1||l2) {
           if (!l1 || (l2 && l2->val <= l1->val)) {
               p->next = l2;
               l2 = l2->next;
           } else {
               p->next = l1;
               l1 = l1->next;
           }
           p = p->next;
       }
       return ans;
    }
};

__________________________________________________________________________________________________
16ms
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return dummy->next;
    }
};
__________________________________________________________________________________________________
8908 kb 
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
    Solution(){
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL){
            return l2;
        } else if (l2 == NULL){
            return l1;
        }
        ListNode* l;
        ListNode* cur = l;
        if (l1->val <= l2->val){
            l = l1;
            cur = l1;
            l1 = l1->next;
        } else{
            l = l2;
            cur = l2;
            l2 = l2->next;
        }
        while (l1 != NULL && l2 != NULL){
            if (l1->val <= l2->val){
                cur->next = l1;
                l1 = l1->next;
            } else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 != NULL){
            cur->next = l1;
        }
        if (l2 != NULL){
            cur->next = l2;
        }
        return l;
    }
};
__________________________________________________________________________________________________
8952 kb
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0),*tmp = head;
        while(true) {
            while(l1 != NULL && l2 != NULL &&l1->val <= l2->val) {
                tmp->next =l1;
                l1 = l1->next;
                tmp = tmp->next;
            }
            if(l1 == NULL) {
                tmp ->next =l2;
                break;
            }

            while(l2 != NULL && l1!= NULL &&l2->val <= l1->val) {
                tmp->next = l2;
                l2 = l2->next;
                tmp = tmp->next;
            }
            if(l2 == NULL) {
                tmp->next = l1;
                break;
            }
        }
        tmp = head;
        head = head->next;
        delete tmp;
        return head;
    }
};
__________________________________________________________________________________________________
