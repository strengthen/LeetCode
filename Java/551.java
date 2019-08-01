__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean checkRecord(String s) {
        boolean absent = false;
        
        for (int i = 0; i < s.length(); ++i) {
            switch(s.charAt(i)) {
                case 'A':
                    if (absent) return false;
                    absent = true;
                    break;
                case 'L':
                    if (i > 1 && s.charAt(i - 1) == 'L' && s.charAt(i - 2) == 'L') return false;
                    break;
            }
        }
        
        return true;
    }
}
__________________________________________________________________________________________________
sample 35620 kb submission
public class Solution {
    public boolean checkRecord(String s) {
        int countA = 0;
        int countL = 0;
        for (int i = 0; i < s.length(); i++) {
             if (s.charAt(i) == 'A') {
                countA++;
            }
        }
        for (int i = 0; i < s.length()-2; i++) {
           
            if (s.charAt(i) == 'L' && s.charAt(i+1) == 'L' && s.charAt(i+2) == 'L') {
                countL++;
            }
        }
        if (countA > 1 || countL >=1) {
            return false;
        }
        return true;
    }
}
__________________________________________________________________________________________________
