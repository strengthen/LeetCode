__________________________________________________________________________________________________
sample 4 ms submission
class MapSum {
    struct Node{
        int val;
        vector<Node*> children;
        Node(){
            val = 0;
            children = vector<Node*>(26, nullptr);
        }
    };
    Node* root;
    unordered_map<string, int> wordToVal;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        int diff = val;
        if(wordToVal.count(key) == 1){
            diff -= wordToVal[key];
        }
        wordToVal[key] = val;
        auto curr = root;
        for(char& c : key){
            if(curr->children[c - 'a'] == nullptr){
                curr->children[c - 'a'] = new Node();
            }
            curr = curr->children[c - 'a'];
            curr->val += diff;
        }
    }
    
    int sum(string prefix) {
        auto curr = root;
        for(char& c : prefix){
            if(curr->children[c - 'a'] == nullptr){
                return 0;
            }
            curr = curr->children[c - 'a'];
        }
        return curr->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
__________________________________________________________________________________________________
sample 9484 kb submission
class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        key2Val[key] = val;
    }
    
    int sum(string prefix) {
        auto it = key2Val.lower_bound(prefix);
        int res = 0;
        while(it != key2Val.end())
        {
            if(it->first.find(prefix) == 0)
                res += it->second;
            ++it;
        }
        return res;
    }
    map<string, int> key2Val;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
__________________________________________________________________________________________________
