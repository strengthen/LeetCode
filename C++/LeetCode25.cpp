__________________________________________________________________________________________________
20ms
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur = head;
        int i;
        for (i = k; i > 0 && cur; i--) {
            cur = cur->next;
        }
        if (i == 0) {
            ListNode *pre = reverseKGroup(cur, k), *next;
            cur = head;
            while (k-- > 0) {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            return pre;
        }
        return head;
    }
};
__________________________________________________________________________________________________
20ms
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode *dummy = new ListNode(-1), *pre = dummy, *cur = head;
        dummy->next = head;
        for (int i = 1; cur; ++i) {
            if (i % k == 0) {
                pre = reverseOneGroup(pre, cur->next);
                cur = pre->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
    ListNode* reverseOneGroup(ListNode* pre, ListNode* next) {
        ListNode *last = pre->next, *cur = last->next;
        while(cur != next) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }
        return last;
    }
};
__________________________________________________________________________________________________
24ms
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
	ListNode * reverseKGroup(ListNode* head, int k) {
		ListNode before(0);
		before.next = head;
		stack<ListNode*> st;
		ListNode* pre = &before;
		while (pre && pre->next)
		{
			ListNode* tmp = pre;
			while (st.size()<k)
			{
				if (pre->next) {
					st.push(pre->next);
					pre = pre->next;
				}
				else {
					break;
				}
			}
			if (st.size() == k) {
				ListNode* t = tmp;
				ListNode* t2 = pre->next;
				while (st.size())
				{
					t->next = st.top();
					st.pop();
					t = t->next;
				}
				t->next = t2;
				pre = t;
			}
			else {
				break;
			}
		}
		return before.next;
	}
};
__________________________________________________________________________________________________
28ms
class Solution {
public:
    /**
    *pre指向可翻转的一段的前一位
    *cur指向要翻转的前一个结点
    *next指向要翻转的结点 头插的方式加到pre的后面
    *tmp记录next的next
    *之后要翻转的是tmp，所以next指向tmp
    *翻转完一段后pre指向cue
    */
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==1)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* p = head;
        int count = 0;
        while(p!=NULL)
        {
            p = p->next;
            count++;
        }
        
        while(count>=k)
        {
          ListNode* cur = pre->next;
          ListNode* next = cur->next;
          int t = k-1;
          while(t--)
          {
              ListNode* tmp = next->next;
              next->next = pre->next;
              pre->next = next;
              cur->next = tmp;
              next = tmp;
          }
          pre = cur;
          count-=k;
        }
        
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};
__________________________________________________________________________________________________
10004 kb
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
    ListNode* reverseGroup(ListNode* begin, ListNode* end){
        ListNode* pre = end;
        while(begin!=end){
            ListNode* tmp = begin->next;
            begin->next = pre;
            pre = begin;
            begin = tmp;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
            return head;
        int count = 0;
        ListNode* begin = head;
        ListNode* end = head;
        while(count<k&&end!=NULL){
            end = end->next;
            count++;
        }
        if (count<k)
            return head;
        ListNode* newHead = reverseGroup(begin, end);
        while(end!=NULL){
            begin = end;
            count = 0;
            while(count<k&&end!=NULL){
                end = end->next;
                count++;
            }
            if (count<k)
                break;
            else{
                head->next = reverseGroup(begin, end);
                head = begin;
            }
        }
        return newHead;
    }
};
__________________________________________________________________________________________________
