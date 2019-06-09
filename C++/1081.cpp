__________________________________________________________________________________________________
class Solution {
public:
    int fact[8] = { 1, 1, 2, 6, 24, 120, 720, 5040 };
unordered_set<string> st;
int uniquePerms(string& s) {
  int cnt[26] = {};
  for (auto ch : s) ++cnt[ch - 'A'];
  auto res = fact[s.size()];
  for (auto n : cnt) res /= fact[n];
  return res;
}
int dfs(string& s, string seq = "", int pos = 0) {
  if (pos >= s.size()) {
    return st.insert(seq).second ? uniquePerms(seq) : 0;
  }
  return dfs(s, seq, pos + 1) + dfs(s, seq + s[pos], pos + 1);
}
int numTilePossibilities(string tiles) {
  sort(begin(tiles), end(tiles));
  return dfs(tiles) - 1;
}
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
