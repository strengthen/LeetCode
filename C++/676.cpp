__________________________________________________________________________________________________
sample 4 ms submission
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
      for (const string& word : dict) {
        words_.insert(word);
        for (int i = 0; i < word.size(); i++) {
          string w = word;
          w[i] = '*';
          count_[w]++;
        }
      }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
      for (int i = 0; i < word.size(); i++) {
        char c = word[i];
        string w = word;
        w[i] = '*';
        if ((count_[w] > 1) || (count_[w] == 1 && !words_.count(word))) {
          return true;
        }
      }
      return false;
    }

private:
    set<string> words_;
    map<string, int> count_;
};
__________________________________________________________________________________________________
sample 9048 kb submission
set<string> Set;
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        Set.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(int i=0;i<dict.size();i++)
            Set.insert(dict[i]);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        string str;
        set<string>::iterator it ;
        for(it=Set.begin();it !=Set.end();it++)
        {
            
            int mismatch = 0;
            str = *it;
            if(str.length() == word.length())
            {
                
                for(int j=0;j<word.length();j++)
                {
                    if(str[j] != word[j])
                    {
                        mismatch++;  
                    } 
                    
                }
                if(mismatch == 1)
                return true;  
            }
            
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
__________________________________________________________________________________________________
