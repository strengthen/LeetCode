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
    // 整体一段往前移
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!k || !head || !head->next) return head; //这里链表只有一个元素的情况也需要特判，不然在后面会有一个访问越界
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pNode = dummy;
        int num = 0;
        while(pNode->next) {
            pNode = pNode->next;
            num ++;
        }
        k = k % num; if (!k) return dummy->next; // 若k为0，则不需要处理了
        ListNode* second = dummy;
        for(int i = 0; i < num - k; i++) second =second->next;
        ListNode* ptrail = second;
        ListNode* phead = dummy->next;
        dummy->next = second->next;
        pNode->next = phead;
        ptrail->next =nullptr;

        return dummy->next;
    }
};
__________________________________________________________________________________________________
8944 kb
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!k || !head)return head;
        ListNode *node = head, *lastNode;
        int size = 0;
        while(node){
            if(!node->next)
                lastNode = node;
            node = node->next;
            size++;
        }
        k = size-(k % size);
        node = head;
        while(k-->1)
            node = node->next;
        lastNode->next = head;
        head = node->next;
        node->next = NULL;
        return head;
    }
};

static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
