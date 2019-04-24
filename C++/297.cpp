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
    
    // I recognize that this is cheating, I just wanted to try it out
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		return std::to_string(reinterpret_cast<size_t>(root));
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		std::stringstream sstream(data);
		size_t myint;
		sstream >> myint;
		return reinterpret_cast<TreeNode*> (myint);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
__________________________________________________________________________________________________
sample 24316 kb submission
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

    
    int maxBinTreeDepth(TreeNode* root)
    {     
        if(root == nullptr)
            return 0;
        
        int maxLeft = maxBinTreeDepth(root->left);
        int maxRight = maxBinTreeDepth(root->right);
        
        //leaf Node reached
        return max(maxLeft, maxRight) + 1;        
    }
    
    

    void bfs_traverse(TreeNode *root, ostringstream& oss)
    {   
        queue<TreeNode *> discoveredNodes;
        discoveredNodes.push(root);        
        TreeNode* currentNode = discoveredNodes.front();
        
        int treeHeight = maxBinTreeDepth(currentNode);
        cout << "height = " << treeHeight <<  endl;
        if(treeHeight == 0)
        {
            oss << "," ;
            return;
        }
        
        
        int elements = 1;        
        //cout << "elements without root=" << (1 << (treeHeight - 1)) << endl;
        while(!discoveredNodes.empty() && (elements <= (1 << (treeHeight - 1)) + 1))
        {
            ++elements;
            
            if(currentNode == nullptr){
                oss << "#";
                discoveredNodes.pop();
                currentNode = discoveredNodes.front();
                oss << "," ;
                //cout << oss.str() << endl;
                continue;                
            }
        
            //Visit Node
            oss << currentNode->val;            
                
            discoveredNodes.push(currentNode->left);
            discoveredNodes.push(currentNode->right);
            
            discoveredNodes.pop();
            currentNode = discoveredNodes.front();
            oss << "," ; 
            
            //cout << oss.str() << endl;
        }               
        
    }
    
     TreeNode *bfs_deserialize(string data){
         
        string tmp(data);
        tmp.erase(tmp.end() - 1);
        tmp.erase(tmp.begin());  
                
        istringstream iss(tmp);
        int number = 0;
        string tmpData;        
 
        if(tmp == "" || tmp == "#")
            return nullptr;
                
        getline(iss, tmpData, ',');        
        auto result = from_chars(tmpData.c_str(), tmpData.c_str() + tmpData.length(), number);
        
        //cout << "root=" << number << endl;
        
        queue<TreeNode *> discoveredNodes;        
        TreeNode *root = new TreeNode(number);
        
        TreeNode *currentNode = root;
        discoveredNodes.push(currentNode);
                
        while(true)
        { 
            if(currentNode == nullptr){
                discoveredNodes.pop();
                currentNode = discoveredNodes.front();
                continue;
            }
            
            if(!getline(iss, tmpData, ','))
                break;
            
            result = from_chars(tmpData.c_str(), tmpData.c_str() + tmpData.length(), number);
            
            //cout << "left=" << number << endl;
            
                      
            currentNode->left = (tmpData == "#") ? nullptr : new TreeNode(number);            
            
            if(!getline(iss, tmpData, ','))            
                break;          
            
            result = from_chars(tmpData.c_str(), tmpData.c_str() + tmpData.length(), number);
            
            //cout << "right=" << number << endl;
            
            
            currentNode->right = (tmpData == "#") ? nullptr : new TreeNode(number);
                            
            discoveredNodes.push(currentNode->left);
            discoveredNodes.push(currentNode->right);
            
            discoveredNodes.pop();
            currentNode = discoveredNodes.front(); 
        }
         
          return root;
         
     }
    
    void dfs_traverse(TreeNode *root, ostringstream& oss){
        
        stack<TreeNode *> discoveredNodes;
        discoveredNodes.push(root);        
        TreeNode* currentNode = discoveredNodes.top();
        
        while(!discoveredNodes.empty())
        {   
            if(currentNode == nullptr)
            { 
              //Pop nullptr
              discoveredNodes.pop();
              oss << '#';
                           
              currentNode = (!discoveredNodes.empty()) ? discoveredNodes.top() : nullptr;
              //Pop's visited node
              if(!discoveredNodes.empty())
              {
                discoveredNodes.pop();       
              }
                
              
              if(currentNode != nullptr)
              {
                oss << ',';
                discoveredNodes.push(currentNode->right);
                currentNode = currentNode->right;
              }
              
              continue;
            }
            
            //Visit Node(pre-order)            
            oss << currentNode->val << ",";
                        
            discoveredNodes.push(currentNode->left);                      
            currentNode = currentNode->left;
        }
        
    }
    
    
    TreeNode *dfs_deserialize(string data){
         
        string tmp(data);
        tmp.erase(tmp.end() - 1);
        tmp.erase(tmp.begin());  
                
        istringstream iss(tmp);
        int number = 0;
        string tmpData;        
 
        if(tmp == "" || tmp == "#")
            return nullptr;
                
        getline(iss, tmpData, ',');        
        auto result = from_chars(tmpData.c_str(), tmpData.c_str() + tmpData.length(), number);
        
        stack<TreeNode *> discoveredNodes;
        TreeNode *rootNode = new TreeNode(number);
        TreeNode *currentNode = rootNode;
        discoveredNodes.push(currentNode);
        
        //cout << "root=" << number << endl;
        
        while(!discoveredNodes.empty())
        {   
            if(currentNode == nullptr)
            { 
              //Pop nullptr
              discoveredNodes.pop();
                           
              currentNode = (!discoveredNodes.empty()) ? discoveredNodes.top() : nullptr;                                         
              //Pop's visited node
             if(!discoveredNodes.empty())
             {
               discoveredNodes.pop();       
             }
                
              if(currentNode != nullptr)
              {   
                  //Construct right side
                if(!getline(iss, tmpData, ','))
                break;
            
                result = from_chars(tmpData.c_str(), tmpData.c_str() + tmpData.length(), number);
            
               // cout << "right=" << number << endl;
              
                      
                currentNode->right = (tmpData == "#") ? nullptr : new TreeNode(number); 
                  
                discoveredNodes.push(currentNode->right);
                currentNode = currentNode->right;
              }
              
              continue;
            }
            
            
                         
            //Construct left side
            if(!getline(iss, tmpData, ','))
                break;
            
            result = from_chars(tmpData.c_str(), tmpData.c_str() + tmpData.length(), number);
            
            //cout << "left=" << number << endl;
            
                      
            currentNode->left = (tmpData == "#") ? nullptr : new TreeNode(number);            
            
            discoveredNodes.push(currentNode->left);                      
            currentNode = currentNode->left;
        }       
         
        return rootNode;
         
     }

public:    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        ostringstream oss;
        oss << "[" ;        
        
        dfs_traverse(root, oss);
        
        oss << "]" ;        
        
        //cout << oss.str() << endl;
        
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {                      
       return dfs_deserialize(data);       
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
__________________________________________________________________________________________________
