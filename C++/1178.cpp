__________________________________________________________________________________________________
sample 136 ms submission
class Solution {
public:
  vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    vector<int> ans;
    
    unordered_map<int, int> freq;
    for (const string& word : words) {
      int mask = 0;
      for (char c : word)
        mask |= 1 << (c - 'a');
      ++freq[mask];
    }
    
    for (const string& p : puzzles) {
      int mask = 0;      
      for (char c : p)
        mask |= 1 << (c - 'a');
      int first = p[0] - 'a';
      int curr = mask;
      int total = 0;
      while (curr) {
        if ((curr >> first) & 1) {
          auto it = freq.find(curr);
          if (it != freq.end()) total += it->second;
        }
        curr = (curr - 1) & mask;
      }
      ans.push_back(total);
    }
    return ans;
  }
};
__________________________________________________________________________________________________
sample 140 ms submission
class Solution {
public:
    inline void setBit(int& bits, int pos) {
        bits |= 1 << pos;
    }
    
    const int checkSubset(int& bits, int pos, const string& s, const unordered_map<int, int>& wordSets) {
        if (pos == s.size()) {
            auto found = wordSets.find(bits);
            return found != wordSets.end() ? found->second : 0;
        }
        int tmp = bits;
        
        // check with the bit unset
        int res = checkSubset(bits, pos + 1, s, wordSets);
        
        // check with the bit set
        setBit(bits, s[pos] - 'a');
        res += checkSubset(bits, pos + 1, s, wordSets);
        
        // reset
        bits = tmp;
        return res;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> res;
        res.reserve(puzzles.size());
        
        // build bit sets
        unordered_map<int, int> wordSets;
        for (const auto& word: words) {
            int bits = 0;
            for (char c: word) {
                setBit(bits, c - 'a');
            }
            wordSets[bits]++;
        }
        
        for (const auto& puzzle: puzzles) {
            // the first bit is always set
            int bits = 0;
            setBit(bits, puzzle[0] - 'a');
            
            // collect occurences for all possible subsets
            int cnt = checkSubset(bits, 1, puzzle, wordSets);
            
            res.push_back(cnt);
        }
        
        return res;
    }
};
__________________________________________________________________________________________________
sample 144 ms submission
class Solution {
public:
    
inline void setBit(int& bits, int pos) 
{
    bits |= 1 << pos;
}
    
const int checkSubset(int& bits, int pos, const string& s, const unordered_map<int, int>& wordSets) 
{
    if (pos == s.size()) 
        {
        auto found = wordSets.find(bits);
        return found != wordSets.end() ? found->second : 0;
        }
    int tmp = bits;
        
    //for each character in a puzzle word, either use it or not use it! 2^6 choices
       
    // check with the bit unset
    int res = checkSubset(bits, pos + 1, s, wordSets);
        
    // check with the bit set
    setBit(bits, s[pos] - 'a');
    res += checkSubset(bits, pos + 1, s, wordSets);
        
    // reset
    bits = tmp;
    return res;
}
    
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) 
{
    vector<int> res;
    res.reserve(puzzles.size());
        
    // build bit sets
    unordered_map<int, int> wordSets;  // word(bit format) -> appearance: 
                                       // abcd adcb the same map, appears twice!
    for (const auto& word: words) 
        {
        int bits = 0;
        for (char c: word) 
            {
            setBit(bits, c - 'a');
            }
        wordSets[bits]++;
        }
        
    for (const auto& puzzle: puzzles) 
        {
        // the first bit is always set
        int bits = 0;
        setBit(bits, puzzle[0] - 'a');
            
        // collect occurences for all possible subsets (for exery puzzle word)
        int cnt = checkSubset(bits, 1, puzzle, wordSets);
            
        res.push_back(cnt);
        }
        
    return res;
}
    
};