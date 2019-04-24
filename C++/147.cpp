__________________________________________________________________________________________________
16ms
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool cmp(ListNode *a, ListNode *b)
{
    return a->val < b->val;
}

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        
        vector<ListNode *> input;
        
        while(head)
        {
            input.push_back(head);
            head = head->next;
        }
        
        //cout << input.size() << endl;
        
        sort(input.begin(), input.end(), cmp);
        
        for (int i = 0; i < input.size() - 1; ++i)
        {
            input[i]->next = input[i+1];
            //cout << input[i]->val << endl;
        }
        
        input[input.size() - 1]->next = NULL;
        
        return input[0];
    }
};
__________________________________________________________________________________________________
9460 kb
// 链表的插入排序
// Runtime: 56 ms, faster than 18.52% of C++ online submissions for Insertion Sort List.
// Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Insertion Sort List.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution 
{
public:
    ListNode* insertionSortList(ListNode* head) 
    {
        // 如果只有一个元素或者没有元素的话直接返回即可，不需要排序
        if (head == 0 || head->next == 0)
            return head;

        for (ListNode *preNode = 0, *curNode = head, *nextNode = head; curNode; curNode = nextNode)
        {
            nextNode = nextNode->next;
            // 迭代寻找适合的插入位置
            ListNode *leftNode = 0, *rightNode = head;
            bool insert = false;
            while (rightNode != curNode)
            {
                if (rightNode->val <= curNode->val)
                {
                    leftNode = rightNode;
                    rightNode = rightNode->next;
                }
                else
                {
                    insert = true;
                    curNode->next = rightNode;
                    
                    if (leftNode)
                        leftNode->next = curNode;
                    else
                        head = curNode;

                    preNode->next = nextNode;
                    break;
                }
            }

            if (!insert)
                preNode = curNode;
        }
        return head;    
    }
};
__________________________________________________________________________________________________
