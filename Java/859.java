__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean buddyStrings(String A, String B) {
        if (A.length() != B.length()) return false;
        
        
        
        if (A.equals(B)) {
            int[] count = new int[26];
            for (int i = 0; i < A.length(); i++) {
                count[A.charAt(i) - 'a']++;
                if (count[A.charAt(i) - 'a'] > 1) return true;
            }
            return false;
        }
        
        char[] a = A.toCharArray();
        char[] b = B.toCharArray();
        
        int count = 0;
        char diffA = 'a';
        char diffB = 'a';
        for (int i = 0; i < a.length; i++) {
            if (a[i] != b[i]) {
                if (count == 1 && (a[i] != diffB || b[i] != diffA)) {
                    return false;
                }
                diffA = a[i];
                diffB = b[i];
                count++;
                if (count > 2) return false;
            }
        }
        return count == 2;
    }
}
__________________________________________________________________________________________________
sample 37220 kb submission
class Solution {
    
    public int[] getCountOfAlphabet(String A) {
        int count[] = new int [26];
        for(int i=0; i<26; i++) {
            count[i] = 0;
        }
        for(int i=0; i<A.length(); i++) {
            count[A.charAt(i)-'a']++;
        }
        return count;
    }
    
    public boolean isAnyCountMoreThanOne(String A) {
        int count[] = getCountOfAlphabet(A);
        for(int i=0; i<count.length; i++) {
            if(count[i]>1) {
                return true;
            }
        }
        return false;
    }
    
    public boolean buddyStrings(String A, String B) {
        // If length is unequal, return false
        if(A.length() != B.length()) {
            return false;
        }
        
        int mismatchCount = 0;
        char pair[][] = new char [2][2];
        for(int i=0; i<A.length(); i++) {
            if(A.charAt(i) != B.charAt(i)) {
                mismatchCount++;
                if(mismatchCount>2){
                    return false;
                }
                pair[mismatchCount-1][0] = A.charAt(i);
                pair[mismatchCount-1][1] = B.charAt(i);
                System.out.println("counr = "+ mismatchCount + " A:" +
                                   A.charAt(i) + " B:" + B.charAt(i));
            }
        }
        System.out.println("mismatchCount = "+ mismatchCount);
        System.out.println("isAnyCountMoreThanOne(A) = "+ isAnyCountMoreThanOne(A));
        System.out.println("1 = "+ (mismatchCount == 0 && isAnyCountMoreThanOne(A)));
        System.out.println("2 = "+ (pair[0][0] == pair[1][1] && pair[0][1] == pair[1][0]));

        if((mismatchCount == 0 && isAnyCountMoreThanOne(A)) || (mismatchCount>0 && pair[0][0] == pair[1][1] && pair[0][1] == pair[1][0])) {
            return true;
        }
        
        return false;
    }
}
__________________________________________________________________________________________________
