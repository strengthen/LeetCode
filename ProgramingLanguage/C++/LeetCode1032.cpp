__________________________________________________________________________________________________
160ms
class TrieNode {
public:
    bool is_word;
    TrieNode * children[26];
    TrieNode(): is_word(false) {
        memset(children, 0, sizeof children);
    }
};

class StreamChecker {
    TrieNode * root;
    string q;
public:
    StreamChecker(vector<string>& words) {
        q = "";
        root = new TrieNode();
        for(string word : words) {
            TrieNode * cur = root;
            int m = word.length();
            for(int i = m - 1; i >= 0; --i) {
                if (cur->children[word[i] - 'a'] == nullptr) {
                    cur->children[word[i] - 'a'] = new TrieNode();
                }
                cur = cur->children[word[i] - 'a'];
            }
            cur->is_word = true;
        }
    }
    
    bool query(char letter) {
        q += letter;
        int m = q.length();
        TrieNode * cur = root;
        for(int i = m - 1; i >= 0; --i) {
            cur = cur->children[q[i] - 'a'];
            if (cur == nullptr) return false;
            if (cur->is_word) return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
__________________________________________________________________________________________________
188ms
class TrieNode {
public:
    bool is_word;
    unordered_map<char, TrieNode*> children;
    TrieNode (): is_word(false) {};
};

class StreamChecker {
    TrieNode root;
    string q;
public:
    StreamChecker(vector<string>& words) {
        for(string word : words) {
            int m = word.length();
            TrieNode * ptr = & root;
            for(int i = m - 1; i >= 0; --i) {
                if (ptr->children.find(word[i]) == ptr->children.end()) {
                    ptr->children[word[i]] = new TrieNode();
                }
                ptr = ptr->children[word[i]];
            }
            ptr->is_word = true;
        }
        q = "";
    }
    
    bool query(char letter) {
        q += letter;
        TrieNode * ptr = & root;
        int m = q.length();
        for(int i = m - 1; i >= 0; --i) {
            auto it = ptr->children.find(q[i]);
            if (it == ptr->children.end()) {
                return false;
            } else {
                ptr = it->second;
                if (ptr->is_word) return true;
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
__________________________________________________________________________________________________
192ms
class StreamChecker {

private:
    struct TrieNode {
        bool isWordEnd;
        TrieNode* next[26];
        TrieNode() {
            isWordEnd = false;
            for(int i=0;i<26;i++) 
                next[i] = NULL;
        };
    };
    
    string q;
    TrieNode* root;
    
public:
    
     /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=word.length()-1;i>=0;i--) {
            if(curr->next[word[i]-'a'] == NULL)
                curr->next[word[i]-'a'] = new TrieNode();
            curr = curr->next[word[i]-'a'];
        } 
        curr->isWordEnd = true;
    }
    
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        q = "";
        for(string& word : words) {
            insert(word);
        }
    }
    
    bool query(char c) {
        q+=c;
        TrieNode *curr = root;
        for (int i=q.length()-1;i>=0;i--) {
            if(curr->next[q[i]-'a'] == NULL)
                return false;
            curr = curr->next[q[i]-'a'];
            if(curr->isWordEnd)
                return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
__________________________________________________________________________________________________
204ms
class StreamChecker {
    class TrieNode {
    public:
        char c;
        bool inDict;
        unordered_map<char, TrieNode*> next;
        TrieNode(char cc=' '):c(cc), inDict(false){};
    } root;
    string q;
public:
    StreamChecker(vector<string>& words) {
        TrieNode *p;
        for (string& w : words) {
            p = &root;
            for (int i=w.size()-1; i>-1; i--) {
                if (!p->next.count(w[i]))
                    p->next[w[i]] = new TrieNode(w[i]);
                p = p->next[w[i]];
            }
            p->inDict = true;
        }
        q = "";
    }
    
    bool query(char c) {
        q += c;
        TrieNode *p = &root;
        for (int i=q.size()-1; i>-1; i--) {
            if (!p->next.count(q[i]))
                return false;
            p = p->next[q[i]];
            if (p->inDict)
                return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
__________________________________________________________________________________________________
244ms
class StreamChecker {
    struct TrieNode {
        bool isEnd;
        TrieNode* child[26];
        TrieNode() {
            isEnd = false;
            memset(child, 0, sizeof(child));
        }
    };
    
    struct Trie {
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }
        
        void insert(const string& s) {
            TrieNode* p = root;
            for (char c: s) {
                if (p->child[c - 'a'] == NULL)
                    p->child[c - 'a'] = new TrieNode();
                p = p->child[c - 'a'];
            }
            p->isEnd = true;
        }
        
        bool find(const string& s) {
            TrieNode* p = root;
            for (char c: s) {
                if (p->child[c - 'a'] == NULL)
                    return false;
                p = p->child[c - 'a'];
                if (p->isEnd) return true;
            }
            return false;
        }
    };
    
    Trie trie;
    string q;
    
public:
    StreamChecker(vector<string>& words) {
        for (string word: words) {
            reverse(word.begin(), word.end());
            trie.insert(word);
        }
    }
    
    bool query(char letter) {
        q = letter + q;
        // cout << q << endl;
        if (q.length() > 200) q = q.substr(0, 200);
        return trie.find(q);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
__________________________________________________________________________________________________
304ms
class StreamChecker {
public:
    
    struct trie {
        trie* child[26];
        bool isLeaf;

        trie(){
            memset(child, 0, sizeof child);
            isLeaf = false;
        }

        void insert(const char *str) { //const char* for strings.c_str()
            if(*str == '\0') isLeaf = true;
            else{
                int cur = *str - 'a';
                if(child[cur] == 0) child[cur] = new trie();
                child[cur]->insert(str+1);
            }
        }

        bool prefixExist(const char* str) { //const char* for strings.c_str()
            if(isLeaf) return true;
            if(*str == '\0') return false;

            int cur = *str - 'a';
            if(child[cur] == 0)  return false;

            return child[cur]->prefixExist(str+1);
        }
    } trie;

    
    StreamChecker(vector<string>& words) {
        for(string s : words){
            reverse(s.begin(), s.end());
            trie.insert(s.c_str());
        }
    }
    
    string q;
    
    bool query(char letter) {
        q += letter;
        if(q.size() > 200) q = q.substr(1);
        string x = q;
        reverse(x.begin(), x.end());
        return trie.prefixExist(x.c_str());
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */