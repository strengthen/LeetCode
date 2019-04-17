__________________________________________________________________________________________________
28ms
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry(0),n1(0),n2(0);
        ListNode *res = new ListNode(0);
        ListNode *tmph=res;
        while(l1!=NULL || l2!=NULL){
            n1=0;
            n2=0;
            if(l1!=NULL){
                n1=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                n2=l2->val;
                l2=l2->next;
            }
            tmph->next=new ListNode((n1+n2+carry)%10);
            tmph=tmph->next;
            carry=(n1+n2+carry)/10;
        }
        if(carry>0){
            tmph->next=new ListNode(carry);
        }
        return res->next;
    }
};
__________________________________________________________________________________________________
32ms
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *result = new ListNode(-1);
        ListNode *tail = result;
        int add = 0;
        
        while(l1 || l2 || add) {

            tail->next = new ListNode(add);
            tail = tail->next;
            
            if(l1) {
                tail->val += l1->val;
                l1 = l1->next;
            }
            
            if(l2) {
                tail->val += l2->val;
                l2 = l2->next;
            }
            
            add = tail->val / 10;
            tail->val %= 10;
        }
         
        return result->next;
    }
};
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* node = nullptr;
        auto overflow = 0;
        
        while (l1 != nullptr || l2 != nullptr){
            auto val = 0;
            val += (l1 != nullptr) ? l1->val : 0;
            val += (l2 != nullptr) ? l2->val : 0;
            val += overflow;
            
            overflow = 0;
            while (val >= 10){
                ++overflow;
                val -= 10;
            }
            
            if (head == nullptr){
                head = new ListNode(val);
                node = head;
            }
            else {
                node->next = new ListNode(val);
                node = node->next;
            }
            
            if (l1!=nullptr) l1 = l1->next;
            if (l2!=nullptr) l2 = l2->next;
        }
        
        while (overflow > 0){
            int val = overflow;
            
            overflow = 0;
            while (val >= 10){
                ++overflow;
                val -= 10;
            }
            
            node->next = new ListNode(val);
            node = node->next;
        }
        
        return head;
    }
};
__________________________________________________________________________________________________
9896 kb 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static int x {[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}()};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto l3=l1;
    for (;;) {
      if (l1==NULL) {
        return l3;
      }
      if (l2!=NULL) {
        l1->val+=l2->val;
        l2=l2->next;
      }
      if (l1->val>=10) {
        l1->val-=10;
        if (l1->next==NULL) {
          l1->next = new ListNode(1);
        }else {
          l1->next->val++;
        }
      }
      if (l1->next==NULL&&l2!=NULL) {
        l1->next=l2;
        l2=NULL;
      }
      l1=l1->next;
    }
  }
};
__________________________________________________________________________________________________
18408 kb
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int bitSum  = p1->val + p2->val;
        p1->val = bitSum%10;
        int add1 = bitSum/10;
        while(p1->next != NULL && p2->next != NULL){
            bitSum = p1->next->val + p2->next->val+add1;
            if(bitSum >= 10){
                p1->next->val = bitSum-10;
                add1 = 1;
            }else{
                p1->next->val = bitSum;
                add1 = 0;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        if(p1->next == NULL && p2->next != NULL){
            p1->next = p2->next;
        }
        while(p1->next != NULL){
            if(  (p1->next->val += add1) >= 10 ){
                p1->next->val -= 10;
                add1 = 1;
            }else{
                add1 = 0;
            }
            p1 = p1->next;
        }
        
        if( add1 == 1){
            // ListNode *node = new ListNode(1);
            p1->next = l2;
            l2->val = 1;
            l2->next = NULL;
        }
        return l1;
    }
};
__________________________________________________________________________________________________
