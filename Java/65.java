__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    // NOTE: 05 is valid
    public boolean isNumber(String s) {
        if (s == null || s.length() == 0) {
            return false;
        }
        s = s.trim();
        
        char[] ss = s.toCharArray();
        boolean pointSeen = false;
        boolean eSeen = false;
        boolean numberAfterE = true;
        boolean numberSeen = false;
        
        for (int i = 0; i < ss.length; i++) {
            if (ss[i] >= '0' && ss[i] <= '9') {
                numberSeen = true;
                numberAfterE = true;
            } else if (ss[i] == '.') {
                if (pointSeen || eSeen /* number after e must be integer*/) {
                    return false;
                }
                pointSeen = true;
            } else if (ss[i] == 'e') {
                if (eSeen || !numberSeen) {
                    return false;
                }
                numberAfterE = false;
                eSeen = true;
            } else if (ss[i] == '+' || ss[i] == '-') {
                // sign can only appear at index 0 or after e
                if (i != 0 && ss[i - 1] != 'e') {
                    return false;
                }
            } else {
                return false;
            }
        }
        
        return numberSeen && numberAfterE;
    }
}
__________________________________________________________________________________________________
sample 35572 kb submission
class Solution {
    public boolean isNumber(String s) {
        if (s == null || s.length() == 0) return false;
        s = s.trim();
        boolean numSeen = false;
        boolean dotSeen = false;
        boolean eSeen = false;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                numSeen = true;
            } else if (c == 'e') {
                if (!numSeen || eSeen) return false;
                eSeen = true;
                numSeen = false;
            } else if (c == '.') {
                if (eSeen || dotSeen) return false;
                dotSeen = true;
            } else if (c == '-' || c == '+') {
                if (i != 0 && s.charAt(i - 1) != 'e') return false;
            } else return false;
        }
        
        return numSeen;
    }
}
__________________________________________________________________________________________________
