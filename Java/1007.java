__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int minDominoRotations(int[] A, int[] B) {
        
        for (int i = 1; i <= 6; i++ ) {
            int ans = check(A, B, i);
            if (ans != -1) return ans;
        }
        return -1;
    }
    
    public int check(int[] A, int[] B, int num) {
        int countA = 0, countB = 0;
        
        for (int i = 0; i < A.length; i++) {
            if (A[i] != num && B[i] != num)
                return -1;
            else if (A[i] != num)
                countA++;
            else if (B[i] != num) 
                countB++;
        }
        return Math.min(countA,countB);
    }
}
__________________________________________________________________________________________________
sample 43768 kb submission
class Solution {
    public int minDominoRotations(int[] A, int[] B) {
        if (A.length != B.length) return -1 ;
        HashMap<Integer,Integer> m1 = new HashMap<> ();                       
        HashMap<Integer,Integer> m2 = new HashMap<> ();                       
        for (int a : A ){
            int cnt = m1.getOrDefault(a, 0) + 1;
            m1.put(a,cnt) ;
        }
        for (int b : B) {
            int cnt = m2.getOrDefault(b, 0) + 1;
            m2.put(b,cnt) ;
        }     
        int min = Integer.MAX_VALUE; ;
        for (int k : m1.keySet()) {
            int len = m1.get(k) + m2.getOrDefault(k, 0) ;            
            if (len >= A.length) {                
                min = Math.min(min, find(A, B, k));
                if (min != Integer.MAX_VALUE) return min ;
            }
        }     
        return min == Integer.MAX_VALUE ? -1 : min ;     
    }
    
    
    private int find (int [] A, int [] B, int target){
        int cntA = 0 ;
        int swapA = 0 ;
        int cntB = 0 ;
        int swapB = 0 ;
        for (int i = 0 ; i < A.length ; ++i) {
            if (A[i] == target) {
                cntA++;
            } else if(B[i] == target) {
                swapA++;
            }
            if (B[i] == target) {
                cntB++;
            } else if(A[i] == target) {
                swapB++;
            }
            
        }
        if (cntA + swapA == A.length && cntB + swapB == A.length) {
            return Math.min(swapA,swapB);
        } else if (cntA + swapA == A.length) {
            return swapA ;
        } else if (cntB + swapB == A.length) {
            return swapB ;
        } else {
            return Integer.MAX_VALUE;
        }
        
    }
}
__________________________________________________________________________________________________
