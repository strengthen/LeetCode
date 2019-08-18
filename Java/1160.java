__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public int countCharacters(String[] W, String C) {
        int[] dict = new int[26];
        Arrays.fill(dict, 0);
        for (int i = 0; i < C.length(); i++) {
            dict[C.charAt(i) - 'a']++;
        }
        int res = 0;
        for (String s : W) {
            int[] copy = new int[26];
            System.arraycopy(dict, 0, copy, 0, 26);
            boolean b = true;
            for (int i = 0; i < s.length(); i++) {
                if (--copy[s.charAt(i) - 'a'] < 0) {
                    b = false;
                    break;
                }
            }
            if (b) res += s.length();
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public int countCharacters(String[] W, String C) {
        int[] base = toArray(C);
        int res = 0;
        for(String s : W) {
            if(isAchievable(base, toArray(s))) {
                res += s.length();
            }
        }
        return res;
    }
    
    private int[] toArray(String s) {
        int[] res = new int[26];
        for(int i = 0; i < s.length(); i++) {
            res[s.charAt(i) - 'a']++;
        }
        return res;
    }
    
    private boolean isAchievable(int[] base, int[] target) {
        for(int i = 0; i < target.length; i++) {
            if(target[i] > base[i]) {
                return false;
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
    public int countCharacters(String[] W, String C) {
        int[] count = new int[256];
        int res = 0;
        for (char ch : C.toCharArray())
            count[ch]++;
        
        for (String w : W) {
            int[] temp = new int[256];
            for (char ch : w.toCharArray())
                temp[ch]++;
            if (match(count, temp))
                res += w.length();
        }
        return res;
    }
    
    private boolean match(int[] a, int[] b) {
        for (int i = 0; i < 256; i++) {
            if (a[i] < b[i]) return false;
        }
        return true;
    }
}