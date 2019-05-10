__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean isScramble(String s1, String s2) {
    int n = s1.length();
    if (n == 1) return s1.equals(s2);
    int[] map1 = new int[128], map2 = new int[128];
    for (int i = 0, cnt1 = 0, cnt2 = 0; i < n-1; i++) {
        if (map1[s1.charAt(i)]++ < 0) cnt1++;
        if (map1[s2.charAt(i)]-- > 0) cnt1++;
        if (cnt1 == i+1 &&
            isScramble(s1.substring(0, cnt1), s2.substring(0, cnt1)) && 
            isScramble(s1.substring(cnt1), s2.substring(cnt1))) return true;
        if (map2[s1.charAt(i)]++ < 0) cnt2++;
        if (map2[s2.charAt(n-1-i)]-- > 0) cnt2++;
        if (cnt2 == i+1 &&
            isScramble(s1.substring(0, cnt2), s2.substring(n-cnt2)) &&
            isScramble(s1.substring(cnt2), s2.substring(0, n-cnt2))) return true;
    }
    return false;
}
}
__________________________________________________________________________________________________
sample 34332 kb submission
class Solution {
    int[] map = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};  //using prime number
    public boolean isScramble(String s1, String s2) {
        int n = s1.length();
        boolean result = false;
        boolean result1 = false;
        boolean result2 = false;
        int key1 = 1;
        int key2 = 1;
        int splitposition = 0;
        for (int j = 0; j <= 1; j++) {
        for (int i = 0; i < n; i++) {
                if (j == 0) {
                    key1 = key1*map[s1.charAt(i)-'a'];
                    key2 = key2*map[s2.charAt(i)-'a'];
                }
                else {
                    key1 = key1*map[s1.charAt(i)-'a'];
                    key2 = key2*map[s2.charAt(n-1-i)-'a'];
                }
                if (n > 3) {
                    if (key1 == key2 && i < n-1) {
                        splitposition = i;
                        if (j == 0) {
                            result1 = isScramble(s1.substring(0,i+1),s2.substring(0,i+1));
                            result2 = isScramble(s1.substring(i+1,n),s2.substring(i+1,n));
                        }
                        else {
                            result1 = isScramble(s1.substring(0,i+1),s2.substring(n-i-1,n));
                            result2 = isScramble(s1.substring(i+1,n),s2.substring(0,n-i-1));
                        }
                        result = result1 & result2;
                        if (result == true) return result;
                    }
                }
            }
            if (n <= 3) {
                if (key1 == key2) return true;
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________
