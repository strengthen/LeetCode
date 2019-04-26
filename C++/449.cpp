__________________________________________________________________________________________________
sample 28 ms submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	void BST_insert(TreeNode* node,TreeNode* newnode)
	{
		if (newnode->val <= node->val)
		{
			if (node->left)
			{
				BST_insert(node->left, newnode);
			}
			else
			{
				node->left = newnode;
			}
		}
		else
		{
			if (node->right)
			{
				BST_insert(node->right, newnode);
			}
			else
			{
				node->right = newnode;
			}
		}
    }

	void preorder(TreeNode* node,string &data)
	{
		if (!node)
			return;
		int val = node->val;
		string revers;
		while (val>=10)
		{
			int mod = val % 10;
			val = val / 10;
			revers += mod + '0';
		}
		revers += val+'0';
		for (int i = 0; i < revers.length(); i++)
			data += revers[revers.length() - 1 - i];
		data += "#";
		if (node->left)
			preorder(node->left, data);
		if (node->right)
			preorder(node->right, data);
	}
	string serialize(TreeNode* root) {
		string data ;
		preorder(root, data);
		return data;
	}

	TreeNode* deserialize(string data) {
		TreeNode* root=NULL;
		int flag = 0;
		string s;
	    int sum = 0;
		for (int i = 0; i < data.length(); i++)
		{
			if (data[i] == '#')
			{
				TreeNode* node = new TreeNode(sum);
				if (flag == 0)
				{
					root = node;
					flag = 1;
				}
				else
				{
					BST_insert(root, node);
				}
				sum = 0;
                continue;
			}
			sum = data[i] - '0' + sum * 10;
		}
		return root;
	}
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
__________________________________________________________________________________________________
sample 22852 kb submission
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==NULL)
            return "";
        
        string ans = "";
        TreeNode* temp;
        q.push(root);
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            
            if(!temp)
            {
                ans+="#_";
                continue;
            }
            ans+=to_string(temp->val);
            ans+="_";
            q.push(temp->left);
            q.push(temp->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")
            return NULL;
        
        string temp = "";
        TreeNode* temp2;
        int i;
        for(i =0;i<data.length();i++)
        {
            if(data[i]=='_')
            {
                i++;
                break;
            }
            
            temp+=data[i];
        }
        int x = stoi(temp);
        temp = "";
        TreeNode* root = new TreeNode(x);
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *l,*r;
        while(!q.empty())
        {
            temp2 = q.front();
            q.pop();
            if(data[i]=='#')
            {
                l = NULL;
                i+=2;
            }
            else
            {
                for(;i<data.length();i++)
                {
                    if(data[i]=='_')
                    {
                        i++;
                        break;
                    }
                    temp+=data[i];
                }
                l = new TreeNode(stoi(temp));
                temp = "";
            }
            if(data[i]=='#')
            {
                r = NULL;
                i+=2;
            }
            else
            {
                for(;i<data.length();i++)
                {
                    if(data[i]=='_')
                    {
                        i++;
                        break;
                    }
                    temp+=data[i];
                }
                r = new TreeNode(stoi(temp));
                temp = "";
            }
            
            temp2->left = l;
            temp2->right = r;
            if(l)
                q.push(l);
            if(r)
                q.push(r);
            
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
__________________________________________________________________________________________________
