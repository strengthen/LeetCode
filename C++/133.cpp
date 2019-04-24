__________________________________________________________________________________________________
24ms
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (not node) return nullptr;
        unordered_map<Node*, Node*> mp;
        return helper(node, mp);
    }
    
    Node* helper(Node* node, unordered_map<Node*, Node*>& mp) {
        if (mp.find(node) != mp.end()) return mp[node];
        
        Node* copy = new Node();
        mp.emplace(node, copy);
        copy->val = node->val;
        copy->neighbors.reserve(node->neighbors.size());
        for (auto c : node->neighbors) {
            copy->neighbors.emplace_back(helper(c, mp));
        }
        return copy;
    }
};
static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
__________________________________________________________________________________________________
16120 kb
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    using Cloned = unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        Cloned cloned;
        cloned[nullptr] = nullptr;
        
        return cloneGraph_BFS(node);
    }
    
    UndirectedGraphNode *cloneGraph_BFS(UndirectedGraphNode *node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        Cloned cloned_;
        
        vector<UndirectedGraphNode *> next_layer;
        auto *new_node = new UndirectedGraphNode(node->label);
        cloned_[node] = new_node;
        next_layer.push_back(node);
        
        while (!next_layer.empty()) {
            vector<UndirectedGraphNode *> new_layer;
            for (auto n: next_layer) {
                auto &neibs = cloned_[n]->neighbors;
                for (auto ne: n->neighbors) {
                    if (cloned_.count(ne) == 0) {
                        auto new_node = new UndirectedGraphNode(ne->label);
                        cloned_[ne] = new_node;
                        new_layer.push_back(ne);
                    }
                    neibs.push_back(cloned_[ne]);
                }
            }
            swap(new_layer, next_layer);
        }
        
        return new_node;
    } 
    
    UndirectedGraphNode *BFS_clone(UndirectedGraphNode *node, Cloned &cloned) {
        if (node == nullptr) {
            return nullptr;
        }
        
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        vector<UndirectedGraphNode *> layer;
        layer.push_back(node);
        cloned[node] = new_node;
        
        while (!layer.empty()) {
            vector<UndirectedGraphNode *> next_layer;
            
            for (auto n: layer) {
                auto &neis = n->neighbors;
                auto &cloned_neis = cloned[n]->neighbors;
                
                for (auto nei: neis) {
                    if (cloned.count(nei) == 0) {
                        cloned[nei] = new UndirectedGraphNode(nei->label);
                        next_layer.push_back(nei);
                    }
                    cloned_neis.push_back(cloned[nei]);
                }
                
                swap(layer, next_layer);
            }
        }
        
        return new_node;
    }
    
    UndirectedGraphNode *DFS_clone(UndirectedGraphNode *node, Cloned &cloned) {
        if (cloned.count(node) == 1) {
            return cloned[node];
        }
        
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        cloned[node] = new_node;
        
        auto &ns = node->neighbors;
        auto &new_ns = new_node->neighbors;
        
        for (auto &n: ns) {
            new_ns.push_back(DFS_clone(n, cloned));
        }
        
        return new_node;
    }
};
__________________________________________________________________________________________________
