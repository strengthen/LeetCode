__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
  int countSubstrings(const string& s) {
    int count = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      int l = i, r = i;
      while (l >= 0 && r < n && s[l--] == s[r++])
        count++;
      l = i, r = i + 1;
      while (l >= 0 && r < n && s[l--] == s[r++])
        count++;
    }
    return count;
  }
};
__________________________________________________________________________________________________
sample 8264 kb submission
const static int _= []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
    public:
    int countSubstrings(string S) {
        int N = S.length(), ans = 0;
        for (int center = 0; center <= 2*N-1; ++center) {
            int left = center / 2;
            int right = left + center % 2;
            while (left >= 0 && right < N && S.at(left) == S.at(right)) {
                ans++;
                left--;
                right++;
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
