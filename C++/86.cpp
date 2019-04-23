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
    ListNode* partition(ListNode* head, int x) {
        ListNode less(-1);
        ListNode *pless = &less;
        ListNode bigger(-1);
        ListNode *pbigger = &bigger;
        
        ListNode *ret = pless;
        ListNode *temp_e = pbigger;
        for (ListNode *curs = head; curs != nullptr; curs = curs->next) {
            if (curs->val < x) {
                pless->next = curs;
                pless = curs;
            }            
            else {
                pbigger->next = curs;
                pbigger = curs;
            }
        }
        
        pless->next = temp_e->next;
        pbigger->next = nullptr;
        return ret->next;
    }
};
__________________________________________________________________________________________________
8384 kb
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
    ListNode* partition(ListNode* head, int x) { 

        ListNode* curNode = head;
        ListNode* curSmallNode = NULL;
        ListNode* curLargeNode = NULL;        
        ListNode* firstLargeNode = NULL;
        while(curNode!=NULL)
        {
            if(curNode->val>=x)
            {        
                if(!firstLargeNode)
                { 
                    firstLargeNode = curNode;
                }
                else
                {
                    curLargeNode->next = curNode;
                }
                 curLargeNode = curNode;
            }
            else
            {
                if(curSmallNode)
                {
                   
                    curSmallNode->next = curNode;
                }
                else
                {
                     head = curNode;
                }
                curSmallNode = curNode;
                if(curSmallNode->next == NULL &&  curLargeNode != NULL)
                {
                    curLargeNode->next = NULL;
                }
            }
            curNode = curNode->next;
        }
        if(curSmallNode)
          curSmallNode->next = firstLargeNode;
        return head;
    }
};
__________________________________________________________________________________________________
