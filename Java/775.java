__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean isIdealPermutation(int[] A) {
        for(int i = 0; i < A.length; i++){
            if(A[i] - i < -1 || A[i] - i > 1){
                return false;
            }
        }
        return true;
        
    }
}
__________________________________________________________________________________________________
sample 39756 kb submission
class Solution {
    public boolean isIdealPermutation(int[] A) {
     for (int i = 0; i < A.length; ++i) {
            if (Math.abs(A[i] - i) > 1) return false;
        }
	return true;   
    }
}
__________________________________________________________________________________________________
