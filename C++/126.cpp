__________________________________________________________________________________________________
32ms
class Node;

typedef vector<string> Ladder;
typedef unordered_set<string> StringSet;
typedef bool (*NodeCmper) (Node*, Node*);
typedef set<Node*, NodeCmper> NodeSet;

class Node
{
public:
    string word;
    vector<Node*> parents;

    Node(string w) : word(w) {}
    void addparent(Node* parent) { parents.push_back(parent); }

    // Yield all children of this node, and:
    //   1) If the child is found in $targetlayer, which means we found ladders that
    //      connect BEGIN-WORD and END-WORD, then we get all paths through this node
    //      to its ROOT node, and all paths through the target child node to its ROOT
    //      node, and combine the two group of paths to a group of ladders, and append
    //      these ladders to $ladders.
    //   2) Elif the $ladders is empty:
    //       2.1) If the child is found in $nextlayer, then get that child, and add
    //            this node to its parents.
    //       2.2) Else, add the child to nextlayer, and add this node to its parents.
    //   3) Else, do nothing.
    void yieldchildren(NodeSet& nextlayer, StringSet& wordlist, NodeSet& targetlayer,
                       vector<Ladder>& ladders, bool forward)
    {
        string nextword = word;
        for (int i = 0, n = nextword.length(); i < n; i++) {
            char oldchar = nextword[i];
            for (nextword[i] = 'a'; nextword[i] <= 'z'; nextword[i]++) {
                if (wordlist.count(nextword)) {
                    // now we found a valid child-word, let's yield a child.
                    Node* child = new Node(nextword);
                    yield1(child, nextlayer, targetlayer, ladders, forward);
                }
            }
            nextword[i] = oldchar;
        }
    }

    // yield one child, see comment of function `yieldchildren`
    void yield1(Node* child, NodeSet& nextlayer, NodeSet& targetlayer,
                vector<Ladder>& ladders, bool forward) {
        auto itr = targetlayer.find(child);
        if (itr != targetlayer.end()) {
            for (Ladder path1 : this->getpaths()) {
                for (Ladder path2 : (*itr)->getpaths()) {
                    if (forward) {
                        ladders.push_back(path1);
                        ladders.back().insert(ladders.back().end(), path2.rbegin(), path2.rend());
                    } else {
                        ladders.push_back(path2);
                        ladders.back().insert(ladders.back().end(), path1.rbegin(), path1.rend());
                    }
                }
            }
        } else if (ladders.empty()) {
            auto itr = nextlayer.find(child);
            if (itr != nextlayer.end()) {
                (*itr)->addparent(this);
            } else {
                child->addparent(this);
                nextlayer.insert(child);
            }
        }
    }

    vector<Ladder> getpaths()
    {
        vector<Ladder> ladders;
        if (parents.empty()) {
            ladders.push_back(Ladder(1, word));
        } else {
            for (Node* parent : parents) {
                for (Ladder ladder : parent->getpaths()) {
                    ladders.push_back(ladder);
                    ladders.back().push_back(word);
                }
            }
        }
        return ladders;
    }
};

bool nodecmp(Node* pa, Node* pb)
{
    return pa->word < pb->word;
}

class Solution {
public:
    vector<Ladder> findLadders(string begin, string end, std::vector<std::string> wordlistorg) {
        StringSet wordlist;
        vector<Ladder> ladders;
        Node headroot(begin), tailroot(end);
        NodeSet frontlayer(nodecmp), backlayer(nodecmp);
        NodeSet *ptr_layerA = &frontlayer, *ptr_layerB = &backlayer;
        bool forward = true;

        
        for (auto && word: wordlistorg)
            wordlist.insert(word);
        
        if (wordlist.count(end) == 0)
            return ladders;
        
        if (begin == end) {
            ladders.push_back(Ladder(1, begin));
            return ladders;
        }

        frontlayer.insert(&headroot);
        backlayer.insert(&tailroot);
        wordlist.insert(end);
        while (!ptr_layerA->empty() && !ptr_layerB->empty() && ladders.empty()) {
            NodeSet nextlayer(nodecmp);
            if (ptr_layerA->size() > ptr_layerB->size()) {
                swap(ptr_layerA, ptr_layerB);
                forward = ! forward;
            }
            for (Node* node : *ptr_layerA) {
                wordlist.erase(node->word);
            }
            for (Node* node : *ptr_layerA) {
                node->yieldchildren(nextlayer, wordlist, *ptr_layerB, ladders, forward);
            }
            swap(*ptr_layerA, nextlayer);
        }

        return ladders;
    }
};


static const auto ___ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
__________________________________________________________________________________________________
13764 kb
class Solution {
public:
    vector<vector<string>> ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        if (wordSet.count(endWord) == 0)
            return {};
        
        wordSet.erase(endWord);
        
        unordered_set<string> searchSet({beginWord});
        unordered_set<string> searchSet2({endWord});
        
        bool forward = true;
        int forward_cnt = 0;
        vector<vector<string>> levels;
        
        while (!searchSet.empty()) {
            unordered_set<string> nextSearchSet;
            
            levels.insert(levels.begin() + forward_cnt, 
                    vector<string>(searchSet.begin(), searchSet.end()));
            if (forward)
                forward_cnt += 1;
            
            for (auto str: searchSet) {
                for (int pos = 0; pos < str.length(); ++pos) {
                    string newWord = str;
                    
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        newWord[pos] = ch;
                        
                        if (searchSet2.count(newWord)) {
                            levels.insert(levels.begin() + forward_cnt, 
                                    vector<string>(searchSet2.begin(), searchSet2.end()));
                            return levels;
                        }
                        if (wordSet.count(newWord)) {
                            nextSearchSet.insert(newWord);
                            wordSet.erase(newWord);
                        }
                    }
                }
            }
            
            if (nextSearchSet.size() < searchSet2.size()) {
                searchSet = std::move(nextSearchSet);
            } else {
                forward ^= true;
                searchSet = std::move(searchSet2);
                searchSet2 = std::move(nextSearchSet);
            }
        }
        
        return {};
    }
    
    bool diff1(string& a, string& b) {
        int diff = 0;
        for (int i = 0; i < a.length(); ++i)
            diff += (a[i] != b[i]);
        return diff <= 1;
    }
    
    void build(vector<vector<string>>& levels, int level, vector<string>& path, vector<vector<string>>& paths) {
        if (level == levels.size()) {
            paths.push_back(path);
            return;
        }
        
        auto last_str = path[level-1];
                
        for (auto s: levels[level]) {
            
            // check diff <= 1
            if (!diff1(last_str, s))
                continue;
            
            path[level] = s;
            build(levels, level+1, path, paths);
        }
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        // BFS search for each levels
        auto levels = ladderLength(beginWord, endWord, wordList);
        
        if (levels.size() == 0)
            return {};
        
        // DFS build path vector
        vector<string> path(levels.size(), levels[0][0]);
        vector<vector<string>> paths;
        
        build(levels, 1, path, paths);
        
        return paths;
    }
};
__________________________________________________________________________________________________
