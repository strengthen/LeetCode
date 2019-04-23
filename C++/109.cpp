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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   
    ListNode * find(ListNode *head)
    {
        ListNode *temp=NULL;
        ListNode *temp1=head;
        ListNode *temp2=head;
        
        while(temp2 && temp2->next)
        {
            temp=temp1;
            temp1=temp1->next;
            temp2=temp2->next->next;
        }
        
        if(temp)
            temp->next=NULL;
        
        return temp1;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        TreeNode *root;
        if(!head)
            return NULL;
        
        ListNode *mid=find(head); 
        root=new TreeNode(mid->val);
        
        if(mid==head)
            return root;
        
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(mid->next);
        return root;
    }
};
__________________________________________________________________________________________________
22484 kb
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void compression(TreeNode *root, int count)
    {
        TreeNode *node = root;
        // cout << "compress " << count << endl;
        
        for (int i = 0; i < count; ++i)
        {
            TreeNode *child = node->right;
            // cout << "right child of " << node->val << ": " << child->val << endl;
            node->right = child->right;
            node = node->right;
            child->right = node->left;
            node->left = child;
        }
    }
    
    int fullSize(int size)
    {
        int n = 1;
        while (n <= size)
        {
            n = n + n + 1;
        }
        return n / 2;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        // psuedo head
        TreeNode *root = new TreeNode(0);
        TreeNode *cur = root;
        int nodeCount = 0;
        while (head != NULL)
        {
            cur->right = new TreeNode(head->val);
            cur = cur->right;
            head = head->next;
            nodeCount++;
        }
        
        // phase 2 of DSW algorithm
        int fullCount = fullSize(nodeCount);
        // cout << "fullCount: " << fullCount << endl;
        compression(root, nodeCount - fullCount);
        
        for (int size = fullCount; size > 1; size /= 2)
            compression(root, size / 2);
        
        return root->right;
    }
};
__________________________________________________________________________________________________
