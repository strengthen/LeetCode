__________________________________________________________________________________________________
sample 20 ms submission
class Solution {
public:
  const int MOD = 1e9 + 7;
  int makeTable(const char* s, int len, std::vector<int>& lps, std::unordered_set<uint32_t>& rs) {
    lps[0] = 0;
    int i = 0;
    int j = 1;
    uint32_t hash = 0;
    while (j < len) {
      if (s[i] == s[j]) {
        hash = (hash * 26 + s[j]) % MOD;
        lps[j] = i + 1;
        int size = j + 1;
        int gsize = size - lps[j];
        if ((size & 1) == 0 and (size % gsize == 0) and (size / gsize) % 2 == 0)
          rs.insert(hash);
        ++i;
        ++j;
      } else {
        if (i > 0) {
          i = lps[i-1];
        } else {
          lps[j] = 0;
          hash = (hash * 26 + s[j]) % MOD;
          ++j;
        }
      }
    }

    // abc abc abc, n = 9, lps[n-1] = 6, len - lps[n-1] = 9 - 6 = 3
    if (lps[len-1] > 0 and len % (len - lps[len-1]) == 0)
      return len - lps[len-1];
    return std::numeric_limits<int>::max();
  }

  int distinctEchoSubstrings(const std::string& s) {
    int n = s.length();
    std::vector<int> lps(n);
    std::unordered_set<uint32_t> rs;
    int high = n - 2;
    for (int i = 0; i <= high; ++i) {
      high = std::min(high, makeTable(&s[i], n - i, lps, rs));
    }
    return rs.size();
  }
};
__________________________________________________________________________________________________
sample 24 ms submission
class Solution {
public:
  const int MOD = 1e9 + 7;
  int makeTable(const char* s, int len, std::vector<int>& lps, std::unordered_set<uint32_t>& rs) {
    lps[0] = 0;
    int i = 0;
    int j = 1;
    uint32_t hash = 0;
    while (j < len) {
      if (s[i] == s[j]) {
        hash = (hash * 26 + s[j]) % MOD;
        lps[j] = i + 1;
        int size = j + 1;
        int gsize = size - lps[j];
        if ((size & 1) == 0 and (size % gsize == 0) and (size / gsize) % 2 == 0)
          rs.insert(hash);
        ++i;
        ++j;
      } else {
        if (i > 0) {
          i = lps[i-1];
        } else {
          lps[j] = 0;
          hash = (hash * 26 + s[j]) % MOD;
          ++j;
        }
      }
    }

    // abcabcabc, n = 9, lps[n-1] = 6, len - lps[n-1] = 9 - 6 = 3
    if (lps[len-1] > 0 and len % (len - lps[len-1]) == 0)
      return len - lps[len-1];
    return std::numeric_limits<int>::max();
  }

  int distinctEchoSubstrings(const std::string& s) {
    int n = s.length();
    std::vector<int> lps(n);
    std::unordered_set<uint32_t> rs;
    int high = n - 1;
    for (int i = 0; i <= high; ++i) {
      high = std::min(high, makeTable(&s[i], n - i, lps, rs));
    }
    return rs.size();
  }
};
__________________________________________________________________________________________________
