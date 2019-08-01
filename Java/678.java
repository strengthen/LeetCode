__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean checkValidString(String s) {
       int lo = 0, hi = 0;
       for (char c: s.toCharArray()) {
           lo += c == '(' ? 1 : -1;
           hi += c != ')' ? 1 : -1;
           if (hi < 0) break;
           lo = Math.max(lo, 0);
       }
       return lo == 0;
    }
}
__________________________________________________________________________________________________
sample 35120 kb submission
class Solution {
	public boolean checkValidString(String s) {
        int bal = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == '*') bal++;
            else if (bal-- <= 0) return false;
        }
        if (bal == 0) return true;
        bal = 0;
        for (int i = s.length()-1; i >= 0; i--) {
            if (s.charAt(i) == ')' || s.charAt(i) == '*') bal++;
            else if (bal-- == 0) return false;
        }
        return true;
    }
}
__________________________________________________________________________________________________
