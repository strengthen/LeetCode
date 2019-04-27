__________________________________________________________________________________________________
sample 4 ms submission
#include <deque>
struct Queue_element
{
  std::string parent;
  std::string current;
  size_t pos;  // position in parent  
    
  Queue_element(std::string p, std::string c, size_t po)
  : parent(p)
  , current(c)
  , pos(po)
  {
      
  }
      
};

class Solution {
public:
    std::unordered_map<std::string, std::string> allowed_cache;
    std::stack<Queue_element> candidates;
    
    void preprocess_allowed(vector<string> &allowed)
    {
        for (int i = 0 ; i < allowed.size(); i++)
        {
            std::string key = allowed[i].substr(0, 2);
            std::string val = allowed[i].substr(2, 1);
            
            auto itr = allowed_cache.find(key);
            if (itr == allowed_cache.end())
            {
                allowed_cache.insert({key, val});
            }
            else
            {
                std::string &old_val = itr->second;
                old_val += val;
            }
                
        }
    }
   
    bool recurse_pyramid(string parent, string candidate, int pos)
    {
       for ( auto i = pos; i <= parent.length() - 2; i++)
       {
            auto key = parent.substr(i, 2);
            auto itr = allowed_cache.find(key);
            if (itr == allowed_cache.end())
            {
                return false;
            }
            else
            {
                 if (itr->second.length() > 1)
                 {
                     for (int j = 1; j < itr->second.length(); j++)
                     {
                          std::string next_candidate = candidate + itr->second[j];
                          if (next_candidate.length() > 1)
                          {
                              std::string temp = next_candidate.substr(next_candidate.length() - 2, 2) ;
                              if (allowed_cache.find(temp) == allowed_cache.end())
                               {
                                  break;
                               }
                               
                           }
                           if(recurse_pyramid(parent, next_candidate, i+1) == true)
                              return true;
                     }
                }
                candidate += itr->second[0];
            }
        }
        if (candidate.length() == (parent.length() - 1))
        {
             if(candidate.length() == 1)
                 return true;
            
             return recurse_pyramid(candidate, "", 0);
        }
        return false;
        
    }
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
           preprocess_allowed(allowed);
           return recurse_pyramid(bottom, "", 0);
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(string str: allowed)
            rcd[str.substr(0, 2)].insert(str.back());
        string current;
        return dfs(bottom, current);
    }

    bool dfs(string bottom, string current) {
        if(bottom.size() == 2 && current.size() == 1)
            return true;
        if(bottom.size() - 1 == current.size())
            return dfs(current, "");
        int len = current.size();
        string key = bottom.substr(len, 2);
        if(rcd.count(key))
        {
            for(char c: rcd[key])
                if(dfs(bottom, current + c))
                    return true;
        }
        return false;
    }
private:
    unordered_map<string, unordered_set<char>> rcd;
};
__________________________________________________________________________________________________
