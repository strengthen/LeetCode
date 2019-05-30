__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String shortestPalindrome(String s) {
        int m = (s == null) ? 0 : s.length();
        if (m == 0) {
            return s;
        }
        
        int left = 0;
        for (int i = m - 1; i >= 0; --i) {
            if (s.charAt(left) == s.charAt(i)) {
                ++left;
            }
        }
        
        if (left == m) {
            return s;
        }
        
        String prefix = s.substring(0, left);
        String suffix = s.substring(left);
        
        StringBuilder sb = new StringBuilder();
        sb.append(suffix);
        
        sb.reverse();
        sb.append(shortestPalindrome(prefix));
        sb.append(suffix);
        
        return sb.toString();
    }
}
__________________________________________________________________________________________________
sample 34348 kb submission
class Solution {
    public String shortestPalindrome(String s) {
        
        if(s == null || s.length() == 0) {
            return "";
        }
        
       String temp = s + "#" + new StringBuilder(s).reverse().toString();
        int[] lps = computeLPSArray(temp);
        StringBuilder subStr = new StringBuilder(s.substring(lps[lps.length-1]));
        return subStr.reverse().toString() + s;
    }
    
    int[] computeLPSArray(String s) {
        int[] lps = new int[s.length()];
        int index = 0;
        
        for(int i=1; i<s.length();) {
            if(s.charAt(i) == s.charAt(index)) {
                lps[i] = index + 1;
                i++;
                index++;
            }else {
                if(index != 0) {
                    index = lps[index-1];
                }else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps;
    }
}
__________________________________________________________________________________________________
