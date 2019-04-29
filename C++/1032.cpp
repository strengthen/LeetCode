__________________________________________________________________________________________________
sample 160 ms submission
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
sample 184 ms submission
struct Node {
    bool isLast;
    Node* next[26];
    Node(bool isLast):isLast(isLast) {
        memset(next, 0, sizeof(next));
    }
};

class StreamChecker {
public:
    Node* trie[26];
    
    StreamChecker(vector<string>& words) {
        memset(trie, 0, sizeof(trie));
        for (string& s : words) {
            Node* cur;
            int ssz = s.size();
            int lastIdx = ssz-1;
            for (int i = lastIdx; i >= 0; --i) {
                int c = s[i] - 'a';
                if (i == lastIdx) {
                    if (!trie[c]) 
                        trie[c] = new Node(false);
                    cur = trie[c];
                } else {
                    if (!cur->next[c]) 
                        cur->next[c] = new Node(false);
                    cur = cur->next[c];
                }
                if (i == 0) cur->isLast = true;
            }
        }
    }
    
    vector<int> Q;
    bool query(char letter) {
        Q.push_back(letter - 'a');
        Node* cur;
        int qsz = Q.size();
        int lastIdx = qsz-1;
        for (int i = lastIdx; i >= 0; --i) {
            int c = Q[i];
            if (i == lastIdx) cur = trie[c];
            else cur = cur->next[c];
            if (cur == NULL) return false;
            if (cur->isLast) return true;
        }
        return false;
    }
};

static int fast = [](){cin.tie(0);ios::sync_with_stdio(0);return 0;}();
__________________________________________________________________________________________________
sample 192 ms submission
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>


using namespace std;

class StreamChecker {
public:
    StreamChecker(const vector<string>& words) {
        initialize_trie(words);
        build_dictionary_automaton();

    }

    bool query(char letter) {
        current = nodes[current].next[letter - 'a'];
        return nodes[current].terminal;
    }

private:

    int current;

    void build_dictionary_automaton()
    {
        queue<pair<int, int>> Q;
        for (int i = 0; i < ALPHABET_SIZE; ++i)
        {
            if (nodes[root].next[i] == -1)
            {
                nodes[root].next[i] = root;
            }
            else
            {
                Q.push(make_pair(root, nodes[root].next[i]));
            }
        }
        while (!Q.empty())
        {
            auto p = Q.front();
            Q.pop();

            if (nodes[p.first].terminal)
            {
                nodes[p.second].terminal = true;
            }
            for (int i = 0; i < ALPHABET_SIZE; ++i)
            {
                int x = nodes[p.first].next[i];
                int y = nodes[p.second].next[i];
                if (y == -1)
                {
                    nodes[p.second].next[i] = x;
                }
                else
                {
                    Q.push(make_pair(x, y));
                }
            }
        }
        current = 0;
    }

    void initialize_trie(const vector<string>& words)
    {
        root = 0;
        nodes.push_back(TrieNode());
        for (auto& word : words)
        {
            auto current = root;
            for (char c : word)
            {
                int offset = c - 'a';
                if (nodes[current].next[offset] == -1)
                {
                    nodes[current].next[offset] = nodes.size();
                    nodes.push_back(TrieNode());
                }
                current = nodes[current].next[offset];
            }
            nodes[current].terminal = true;
        }
    }

    static const int ALPHABET_SIZE = 26;

    struct TrieNode
    {
        int next[ALPHABET_SIZE];
        bool terminal;
        TrieNode()
        {
            fill(next, next + ALPHABET_SIZE, -1);
            terminal = false;
        }
    };

    vector<TrieNode> nodes;
    int root;

};

static const int accelerate = []() {  
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */