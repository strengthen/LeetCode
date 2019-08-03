__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int distinctSubseqII(String S) {
        int[] dict = new int[26]; // Save 'total' count when a character appears.
        int total = 1; //Empty string, starting at count 1
        for (char c : S.toCharArray()) {
            int combo = total * 2 - dict[c - 'a']; // New - Duplicates
            dict[c - 'a'] = total; // if 'c' ever appears again, it will clash with the current combos.
            total = combo < 0 ? combo + 1000000007 : combo % 1000000007; // mod and fix negative mods
        }
        return total - 1; // Subtract the empty string
 
    }
}
__________________________________________________________________________________________________
sample 35216 kb submission
class Solution {
    public int distinctSubseqII(String S) {
        long[] end = new long[26];
        long mod = (long) Math.pow(10, 9) + 7;
        for (char c : S.toCharArray())
            end[c - 'a'] = Arrays.stream(end).sum() % mod + 1;
        return (int)(Arrays.stream(end).sum() % mod);
    }
}
__________________________________________________________________________________________________
