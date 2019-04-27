__________________________________________________________________________________________________
sample 28 ms submission
struct Trie {
    const string* ref = nullptr;
    Trie* child[26] = {nullptr};

    void Insert(const string& word) noexcept {
      Trie* t = this;
      for (char c : word) {
        c -= 'a';
        if (t->child[c] == nullptr) {
          t->child[c] = new Trie();
        }
        t = t->child[c];
      }
      t->ref = &word;
    }
    const string* FindLongest() const noexcept {
      const string *s = nullptr, *s1 = nullptr;
      for (int i = 0; i < 26; i++) {
        if (child[i] != nullptr && child[i]->ref != nullptr) {
          if (s == nullptr) {
            s = child[i]->ref;
          }

          s1 = child[i]->FindLongest();
          if (s1 != nullptr && (s == nullptr || s1->size() > s->size())) {
            s = s1;
          }
        }
      }
      return s;
    }
  };

class Solution {
 public:
  static string longestWord(const vector<string>& words) {
    Trie t;
    for (const auto &word : words) {
      t.Insert(word);
    }
    auto s = t.FindLongest();
    if (s != nullptr) {
      return *s;
    }
    return "";
  }
};

__attribute__((constructor)) void _() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cerr.tie(nullptr);
}
__________________________________________________________________________________________________
sample 12824 kb submission
class Solution {
public:
    string longestWord(vector<string>& words) {
        constexpr long q = 1000033;
        constexpr long p = 257;
        std::bitset<q> m;
        
        for (string& str : words) {
            long h = 0;
            
            for (auto ch : str) 
                h = (h * p + ch) % q;
            
            m.set(h);
        }
        
        auto res = std::begin(words);
        const auto ed = std::end(words);
        int max_count = 0;
        
        for (auto st = std::begin(words); st != ed; st++) {
            if ((*st).size() < max_count)
                continue;
            long h = 0;
            int count = 0;
            
            for (auto ch : *st) {
                h = (h * p + ch) % q;
                
                if (!m[h])
                    break;
                
                count ++;
            }
            
            if (count == (*st).size()) {
                if (count > max_count) {
                    res = st;
                    max_count = count;
                } else if (count == max_count && *st < *res) {
                    res = st;
                }
            }            
        }        
        return *res;
    }
};
__________________________________________________________________________________________________
