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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return NULL;
        }
        ListNode *curr=head;
        int length=0;
        while(curr != NULL){
            length++;
            curr = curr->next;
        }
        curr=head;

        int count=1; 
        if(length == 1){
            return NULL;
        }
        if(n == length) {
            curr=curr->next;
            return curr;
        }  
        while(count<=length-n) {
            if (count == length-n) {
                curr->next = curr->next->next;
            }
            count++;
            curr=curr->next;
        }
       return head;
  }
};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
ListNode *left, *right;
int i;

    left = head;
    right = head;

    for (i = 0; i < n; i++)
    {
        if (right == 0)
            return head;

        right = right -> next;
    }

    if (right == 0)
    {
        head = head -> next;
        return head;
    }

    while (right -> next)
    {
        left = left -> next;
        right = right -> next;
    }

    left -> next = left -> next -> next;

    return head;        
    }
};
__________________________________________________________________________________________________
12ms
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return NULL;
        ListNode *pre = head, *cur = head;
        for (int i = 0; i < n; ++i) cur = cur->next;
        if (!cur) return head->next;
        while (cur->next) {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};
__________________________________________________________________________________________________
8668 kb
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *h = head;
        ListNode *t = head;
        for (int i = 0; i < n; ++i)
            t = t->next;
        
        if (!t)
            return head->next;
        
        while (t->next) {
            h = h->next;
            t = t->next;
        }
        
        h->next = h->next->next;
        return head;
    }
};

static auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
8680 kb
class Solution {
public:

  // -1->1->NULL
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
    ListNode fake(0);
    fake.next = head;

    ListNode *first = &fake, *second = &fake;
    while (n-- > 0) {
      second = second->next;
      if (!second) {
        return head;
      }
    }

    while (second->next) {
      first = first->next;
      second = second->next;
    }

    ListNode* temp = first->next;
    first->next = temp->next;
    delete temp;
    return fake.next;
  }
};
__________________________________________________________________________________________________
