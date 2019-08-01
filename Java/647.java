__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
        public int countSubstrings(String s) {
            int count = 0;
            for(int i=0;i<s.length();i++) {
                count = count+palindromeCount(s, i, i);
                if (i+1<s.length() && s.charAt(i) == s.charAt(i+1)) {
                    count = count+palindromeCount(s, i, i+1);
                }
            }
            return count;
        }

        private int palindromeCount(String s, int L, int R) {
            int count = 0;
            while(L >= 0 && R < s.length()) {
                if (s.charAt(L--)!=s.charAt(R++)) {
                    break;
                }
                count++;
            }
            return count;
        }
    }
__________________________________________________________________________________________________
sample 35440 kb submission
class Solution {
    int cnt = 0;

    public int countSubstrings(String s) {
        for (int i = 0; i < s.length(); i++) {
            expand(i, i, s);
            expand(i, i + 1, s);
        }
        return cnt;
    }

    public void expand(int l, int r, String s) {
        while (l >= 0 && r < s.length() && s.charAt(l) == s.charAt(r)) {
            cnt++;
            l--;r++;
        }
    }
}
__________________________________________________________________________________________________
