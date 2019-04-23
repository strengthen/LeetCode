__________________________________________________________________________________________________
20ms
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recHelper(nums, 0 , (int)nums.size() - 1);
    }
  
private:
    TreeNode* recHelper(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        int mid = left + (right - left) / 2; // the root is the midian. 
      
        TreeNode *root = new TreeNode(nums[mid]);
        root->left  = recHelper(nums, left, mid - 1);
        root->right = recHelper(nums, mid + 1, right);
      
        return root;
    }
};
__________________________________________________________________________________________________
19636 kb
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
        cout << "compress " << count << endl;
        
        for (int i = 0; i < count; ++i)
        {
            TreeNode *child = node->right;
            cout << "right child of " << node->val << ": " << child->val << endl;
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
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() < 1)
        {
            return NULL;
        }
        
        // create a linkedlist of TreeNode
        // psuedo root node
        TreeNode *root = new TreeNode(0);
        TreeNode *cur = root;
        
        for (auto it = nums.begin(); it < nums.end(); ++it)
        {
            cur->right = new TreeNode(*it);
            cur = cur->right;
        }
        
        // phase 2 of DSW algorithm
        int fullCount = fullSize(nums.size());
        cout << "fullCount: " << fullCount << endl;
        compression(root, nums.size() - fullCount);
        
        for (int size = fullCount; size > 1; size /= 2)
            compression(root, size / 2);
        
        return root->right;
    }
};
__________________________________________________________________________________________________
