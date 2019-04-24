__________________________________________________________________________________________________
sample 4 ms submission
static const int _ = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
  
bool isAnagram(std::string S, std::string T) {
  std::vector<int> CharFreqs(128, 0);
  for (const auto &SCh : S)
    CharFreqs[SCh]++;
  for (const auto &TCh : T) {
    if (CharFreqs[TCh] == 0)
      return false;
    CharFreqs[TCh]--;
  }

  for (const auto &CharFreq : CharFreqs) {
    if (CharFreq > 0)
      return false;
  }
  return true;
}  
};
__________________________________________________________________________________________________
sample 8768 kb submission
class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
        return toFrequency(s) == toFrequency(t);
    }

private:
    unordered_map<char, int> toFrequency(const string& str) {
        unordered_map<char, int> res;
        for (char ch : str) {
            res[ch]++;
        }
        return res;
    }
};
__________________________________________________________________________________________________
