__________________________________________________________________________________________________
sample 0 ms submission
class Solution {    
   
    public void append(StringBuilder sb, char ch, int count) {
        while(count-->0) sb.append(ch);     
    }
    
    public String strWithout3a3b(int A, int B) {
        StringBuilder sb = new StringBuilder(); 
        char maxCh = (A>=B) ? 'a' : 'b'; 
        char minCh = maxCh == 'a' ? 'b' : 'a'; 
        int maxCount = A>=B ? A : B; 
        int minCount = maxCount == A ? B : A; 
        while(minCount>0 || maxCount>0) {
            if(maxCount == minCount) {
                for(int i=0; i<maxCount; i++) {
                    sb.append(minCh); sb.append(maxCh); 
                }
                break; 
            } else {
                int m1 = maxCount > 2 ? 2 : maxCount; 
                int m2 = minCount > 1 ? 1 : minCount; 
                if(m1 > 0) {
                    append(sb, maxCh, m1);
                    maxCount-=m1; 
                }
                if(m2 > 0) {
                    append(sb, minCh, m2) ;
                    minCount-=m2; 
                }
            }
        }
        return new String(sb);
    }
}
__________________________________________________________________________________________________
sample 35524 kb submission
class Solution {
    public String strWithout3a3b(int A, int B) {
StringBuilder ans = new StringBuilder();

        while (A > 0 || B > 0) {
            boolean writeA = false;
            int L = ans.length();
            if (L >= 2 && ans.charAt(L-1) == ans.charAt(L-2)) {
                if (ans.charAt(L-1) == 'b')
                    writeA = true;
            } else {
                if (A >= B)
                    writeA = true;
            }

            if (writeA) {
                A--;
                ans.append('a');
            } else {
                B--;
                ans.append('b');
            }
        }

        return ans.toString();
        
    }
}
__________________________________________________________________________________________________
