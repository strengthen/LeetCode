__________________________________________________________________________________________________
sample 136 ms submission
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root){
            int xd = 0;
            for(auto p : root->children){
                if(p){
                    int td = maxDepth(p);
                    if(xd < td){
                        xd = td;
                    }
                }
            }
            return xd + 1;
        }
        else{
            return 0;
        }
    }
};

struct InputBooster {
    InputBooster(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
}ib;
__________________________________________________________________________________________________
sample 31888 kb submission
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void maxDepthHelper(Node* root,int depth,int& maxdepth){
        if(root!=nullptr){
            depth++;
            if(root->children.size()==0){
                maxdepth=max(maxdepth,depth);
            }
            for(const auto child:root->children){
                maxDepthHelper(child,depth,maxdepth);
            }
        }
    }
    int maxDepth(Node* root) {
        int maxdepth = INT_MIN;
        maxDepthHelper(root,0,maxdepth);
        return maxdepth==INT_MIN?0:maxdepth;
    }
};

static auto speedup = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
