__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int longestDecomposition(String text) {
        return helper(text, 0);
    }
    
    private int helper(String curr_str, int count) 
    { 
        if (curr_str == null || curr_str.isEmpty()) 
            return count;
  
        if (curr_str.length() <= 1) return count + 1;
  
        int n = curr_str.length(); 
        for (int i = 0; i < n/2; i++) 
        {
            if (curr_str.substring(0, i + 1).equals(curr_str.substring(n-1-i, n))) 
            {
                
                return helper(curr_str.substring(i+1, n-1-i), count + 2); 
            } 
        }
        return count + 1; 
    } 
}
__________________________________________________________________________________________________
5ms
class Solution {
    public int longestDecomposition(String S) {
       int res = 0, n = S.length();
       String l = "", r = "";
       for (int i = 0; i < n; ++i) {
           l = l + S.charAt(i);
           r = S.charAt(n - i - 1) + r;
           if (l.equals(r)) {
               ++res;
               l = "";
               r = "";
           }
       }
       return res;
   }
}
__________________________________________________________________________________________________
