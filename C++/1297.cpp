__________________________________________________________________________________________________
sample 24 ms submission
static const unsigned long long int MOD=pow(2,63)-1;    
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unsigned long long p = pow(26, minSize);
        unordered_map<unsigned long long, int> m1;
        unsigned long long hash = 0;
        int record[26] = {0};
        int diff = 0;
        
        for (int i = 0, j = 0; i < s.size(); ++i)
        {
            if (++record[s[i] - 'a'] == 1) ++diff;
            hash = (hash * 26 + (s[i] - 'a')) % MOD;
            
            if (j <= i && (i - j + 1 > minSize)) 
            {
                if (--record[s[j] - 'a'] == 0) --diff;
                hash -= (s[j] - 'a') * p;
                ++j;
            }
            
            if (i - j + 1 == minSize && diff <= maxLetters) 
            {
                ++m1[hash];
            }
            
        }
        
        int ans = 0;
        for (auto x : m1)
        {
            ans = max(ans, x.second);
        }
        return ans;
    }
};
__________________________________________________________________________________________________
sample 28 ms submission
[[maybe_unused]] static auto const fast = []{return ios_base::sync_with_stdio(false);}();

inline namespace zm
{
 template <typename K,
           typename T,
           typename Hash      = std::hash<K>,
           typename KeyEqual  = std::equal_to<K>,
           typename Allocator = std::allocator<std::pair<const K,T>>>
 struct hashmap : std::unordered_map<K,T,Hash,KeyEqual,Allocator>
 {
  using std::unordered_map<K,T,Hash,KeyEqual,Allocator>::unordered_map;
  bool has (K const& key) const
  {
   return this->find(key) != this->end();
  }
  bool contains (K const& key) const
  {
   return this->has(key);
  }
 };
}

struct Solution
{
 int maxFreq (string const& s, int const maxLetters, int const minSize, int const maxSize)
 {
  return solve(s,maxLetters,minSize);
 }
 int solve (string const& s, int const M, int const size)
 {
  hashmap<string_view,int> occurrences;
  for (auto [count,counts,i,j] = tuple(0,array<int,26>{},0,size); j <= s.size(); ++i, ++j)
  {
   if (i == 0)
   {
    for (auto i = 0; i < j; ++i)
    {
     if (counts[s[i]-'a']++ == 0)
     {
      ++count;
     }
    }
   }
   else
   {
    if (--counts[s[i-1]-'a'] == 0)
    {
     --count;
    }
    if (counts[s[j-1]-'a']++ == 0)
    {
     ++count;
    }
   }
   if (count <= M)
   {
    ++occurrences[{&s[i],size_t(j-i)}];
   }
  }
  if (occurrences.empty()) { return 0; }
  return max_element(begin(occurrences),end(occurrences),[&](auto&x,auto&y){return x.second<y.second;})->second;
 }
};
__________________________________________________________________________________________________
