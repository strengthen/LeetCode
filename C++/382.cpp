__________________________________________________________________________________________________
sample 28 ms submission
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
const static int _= []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        srand (time(NULL));
        m_head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int guess = rand();
        ListNode * runner = m_head;
        int listSize=1;
        bool largerThanList = false;
        for (int i=0; i<guess; i++)
        {            
            if (runner->next)
                runner=runner->next;
            else
            {
                largerThanList=true;
                break;
            }                
            listSize++;
        }
        if (largerThanList)
        {
            int n = guess%listSize;
            runner = m_head;
            for (int i=0; i<n; i++)
                runner = runner->next;
        }
        
        return runner->val;
    }
private:
    ListNode * m_head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
__________________________________________________________________________________________________
sample 16160 kb submission
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        len=0;
        ListNode *cur=head;
        this->head=head;
        while(cur)
        {
            ++len;
            cur=cur->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int t=rand()%len;
        ListNode*cur=head;
        while(cur&&t)
        {
            t--;
            cur=cur->next;
        }
        return cur->val;
    }
private:
    int len;
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
__________________________________________________________________________________________________
