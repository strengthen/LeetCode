__________________________________________________________________________________________________
sample 112 ms submission
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    
    vector<string> sol;
      
      ios::sync_with_stdio(false);
      cin.tie(0);
      
    int freq[26] = {0};
    
    for(int i = 0 ; i < B.size() ; i++)
    {
      int freqTemp[26] = {0};
      
      for(int j = 0 ; j < B[i].size() ; j++)
      {
        freqTemp[B[i][j]-'a']++;
      }
      
      for(int j = 0 ; j < 26 ; j++)
      {
        freq[j] =  max(freq[j],freqTemp[j]);
      }
      
    }
             
        for(int allWords = 0 ; allWords < A.size() ; allWords++)
        {
          
          int k;
          int wordFreq[26] = {0};
          
          for(int i = 0 ; i < A[allWords].size() ; i++)
          {
            wordFreq[A[allWords][i]-'a']++;
          }
          
          int all;
          for(all = 0 ; all  < 26 ; all++)
          {
            if(freq[all] > wordFreq[all])
              break;
          }
        
          if(all == 26)
          {
            sol.push_back(A[allWords]);
          }

    }
      return sol;
    }
};
__________________________________________________________________________________________________
sample 38524 kb submission
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        std::vector<int> cc(26), cs(26);
        for (auto && w: B) {
            counting(w, cc);
            for (int i = 0; i < 26; ++i) {
                cs[i] = std::max(cs[i], cc[i]);
            }
        }
        std::vector<std::string> rs;
        for (auto && w: A) {
            counting(w, cc);
            int i = 0;
            for (i = 0; i < 26; ++i) {
                if (cc[i] < cs[i]) {
                    break;
                }
            }
            if (i == 26) {
                rs.push_back(w);
            }
        }
        return rs;
    }

    inline void counting(std::string & w, std::vector<int> & cc) {
        std::fill(cc.begin(), cc.end(), 0);
        for (auto && c: w) {
            cc[c-'a'] += 1;
        }
    }
};
__________________________________________________________________________________________________
