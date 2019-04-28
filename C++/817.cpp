__________________________________________________________________________________________________
sample 20 ms submission
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static int x = [](){std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0;}();

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        if(!head)
            return 0;
        ListNode* curr = head;
        int components = 0;
        vector<bool> v(10000, false);
        for(auto n : G)
            v[n] = true;
        while(curr)
        {
            if(v[curr->val]){
                while(curr && v[curr->val])
                    curr = curr->next;
                components++;
            }
            else
                curr = curr->next;    
        }
        return components;
        
    }
};
__________________________________________________________________________________________________
sample 12928 kb submission
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
    int numComponents(ListNode* head, vector<int>& G) {
        sort(G.begin(), G.end());
        int c = 0;
        bool f = 0;
        for (ListNode* cur = head; cur; cur = cur->next) {
            if (binary_search(G.begin(), G.end(), cur->val)) f = 1;
            else if (f) f = 0, c++;
        }
        return c+(int)f;
    }
};
__________________________________________________________________________________________________
