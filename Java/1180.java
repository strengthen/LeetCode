__________________________________________________________________________________________________
class Solution {
    public int countLetters(String S) {
        int ans = 0, repeat = 1;
        for (int i = 1; i < S.length(); ++i, ++repeat) {
            if (S.charAt(i) != S.charAt(i - 1)) { // previous char consectively occurs 'repeat' times.
                ans += repeat * (repeat + 1) / 2;
                repeat = 0;
            }
        }
        return ans + repeat * (repeat + 1) / 2;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
