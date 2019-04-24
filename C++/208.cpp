__________________________________________________________________________________________________
sample 56 ms submission
static auto _=[](){cin.tie(nullptr);ios::sync_with_stdio(false);return 0;}();
class Trie
{
    typedef struct node {
        bool word;
        node* next[26];
        node() : word(false) { memset(next, 0, sizeof(next)); }
    } *Node;
    
    Node root;
    
public:
    /** Initialize your data structure here. */
    Trie()
    {
        this->root = new node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node current = this->root;
        for (auto letter : word)
        {
            current =
                current->next[letter - 'a'] == nullptr ?
                current->next[letter - 'a'] = new node() :
                current->next[letter - 'a'];
        }
        current->word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node current = this->root;
        for (auto letter : word)
        {
            current = current->next[letter - 'a'];
            
            if (current == nullptr)
                return false;
        }
        
        return current->word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node current = this->root;
        for (auto letter : prefix)
        {
            current = current->next[letter - 'a'];
            
            if (current == nullptr)
                return false;
        }
        
        return current != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
__________________________________________________________________________________________________
sample 23976 kb submission
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
    
        prefixs += "_"+word+"_";
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        return(prefixs.find("_"+word+"_")!=string::npos);
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        if(prefixs.find("_"+prefix)!=string::npos) { return(true); }
        
        return(false);
        
    }
    
    unordered_set<string> m_set;
    string prefixs;
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
__________________________________________________________________________________________________
