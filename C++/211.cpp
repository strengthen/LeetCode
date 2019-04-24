__________________________________________________________________________________________________
sample 64 ms submission
void beforeMain(void) __attribute__((constructor));

void beforeMain(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}


class WordDictionary {
  struct trie {
    bool end = false;
    trie* child[26UL] = {nullptr};
  };
  trie data;

  
  bool search(const trie* t, const char* w, const char* end) {
    for (; w < end; ++w) {
      if (*w == '.') {
        for (int8_t j = 0; j < 26; ++j) {
          if (t->child[j]  && search(t->child[j], w + 1, end)) {
            return true;
          }
        }
        return false;
      }
      const int8_t c = *w - 'a';
      if (!t->child[c]) {
        return false;
      }
      t = t->child[c];
    }
    return t->end;
  }
    
 public:
  inline void addWord(const string& word) {
    trie* t = &data;
    for (const int8_t& c : word) {
      if (!t->child[c - 'a']) {
        t->child[c - 'a'] = new trie;
      };
      t = t->child[c - 'a'];
    }
    t->end = true;
  }
  inline bool search (const string& word) {
    const char* wData = word.data();
    return search(&data, wData, wData + word.size());
  }
};
__________________________________________________________________________________________________
sample 31204 kb submission
class WordDictionary {
public:
    vector<string> dic;
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        dic.push_back(word);        
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        auto it = dic.begin();
        int i;
        int n = word.length();
        
        while(it != dic.end()) {
            if ( n == it->length()) {
                for (i = 0; i < n; i++) {
                    if (word[i] == '.') 
                        continue;
                    if (word[i] != (*it)[i])
                        break;
                }
                if (i == n)
                    return true;                
            }            
            it++;
        }

        return false;        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
__________________________________________________________________________________________________
