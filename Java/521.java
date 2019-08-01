__________________________________________________________________________________________________
0ms
class Solution {
    public int findLUSlength(String a, String b) {
    return a.equals(b) ? -1 : Math.max(a.length(), b.length());
  }
}
__________________________________________________________________________________________________
sample 35212 kb submission
class Solution {
    public int findLUSlength(String a, String b) {
        if(a.equals(b)) {
            return -1;
        }
        
        if(a.length() >= b.length()) {
            return a.length();
        } else if (a.length() < b.length()) {
            return b.length();
        } 
        
        return a.length();
    }
}
__________________________________________________________________________________________________
