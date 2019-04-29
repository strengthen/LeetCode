__________________________________________________________________________________________________
sample 164 ms submission
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static int x = [](){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();


class Solution {
public:
    
    ListNode* reverse_linked(ListNode* head) {
        if(head == NULL or head -> next == NULL) {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* nex = head -> next;
        curr -> next = NULL;
        while(nex != NULL) {
            ListNode* after_next = nex -> next;
            nex -> next = curr;
            curr = nex;
            nex = after_next;
        }
        return curr;
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        
        vector < int > ans;
        if(head == NULL) {
            return ans;
        }
        
        head = reverse_linked(head);
        stack < int > st;
        
        ListNode* curr = head;
        while(curr != NULL) {
            while(!st.empty() and st.top() <= (curr -> val)) {
                st.pop();
            }
            
            if(st.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(st.top());
            }
            st.push(curr -> val);
            curr = curr -> next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
__________________________________________________________________________________________________
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
    vector<int> nextLargerNodes(ListNode* h) {
  vector<int> res, stack;
  for (auto p = h; p != nullptr; p = p->next) res.push_back(p->val);
  for (int i = res.size() - 1; i >= 0; --i) {
    auto val = res[i];
    while (!stack.empty() && stack.back() <= res[i]) stack.pop_back();
    res[i] = stack.empty() ? 0 : stack.back();
    stack.push_back(val);
  }
  return res;
}
};
__________________________________________________________________________________________________
sample 168 ms submission
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverse_list(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* prev = NULL;
        while (head) {
            auto node = prev;
            prev = head;
            head = head->next;
            prev->next = node;
        }
        return prev;
    }
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        head = reverse_list(head);
        if (!head) return result;
        ListNode* prev = NULL;
        stack<int> st;
        while (head) {
            if(st.empty()) {
                result.push_back(0);
            } else {
                while (!st.empty() && st.top() <= head->val) {
                    st.pop();
                }
                if (st.empty()) {
                    result.push_back(0);                    
                } else {
                    result.push_back(st.top());
                }
            }
            st.push(head->val);
            head = head->next;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

auto ___ = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();