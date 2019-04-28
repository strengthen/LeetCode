__________________________________________________________________________________________________
sample 4 ms submission
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
 public:
  void findSecretWord(std::vector<std::string>& wordlist, Master& master) {
    while (1) {
      int index = rand() % wordlist.size();
      int matches = master.guess(wordlist[index]);
      if (matches == 6) {
        break;
      }
      refresh_wordlist(wordlist, index, matches);
    }
  }

    void refresh_wordlist(std::vector<std::string>& wordlist, int index, int matches) {
      std::vector<std::string> new_words;
      for (int i = 0; i < wordlist.size(); ++ i) {
        if (i == index) continue;
        if (get_matches(wordlist[i], wordlist[index]) == matches) {
          new_words.push_back(wordlist[i]);
        }
      }
      wordlist = new_words;
    }

    int get_matches(const std::string& a, const std::string& b) {
      int result = 0;
      for (int i = 0; i < a.length(); ++ i) {
        result += a[i] == b[i];
      }
      return result;
    }
};
__________________________________________________________________________________________________
sample 8492 kb submission
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int match(const string a, const string b) {
        int ans = 0; 
        
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == b[i]) ++ans;
        }
        return ans;
    }
    
    void shrinkWordList(vector<string>& wordlists, const string guessWord, const int matches) {
     
        vector<string> tmp;
        
        for (string word : wordlists) {
            int m = match(word, guessWord);
            if (m == matches) {
                tmp.push_back(word);
            }
        }
        wordlists = tmp;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        
        string target = wordlist[random() % wordlist.size()];
        int Count = 10;
        
        while (Count--) {
            int matches = master.guess(target);
            
            shrinkWordList(wordlist, target, matches);
            
            target = wordlist[random() % wordlist.size()];
        }
    }
};
__________________________________________________________________________________________________
