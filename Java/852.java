__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int i = 0;
        while(i < A.length - 1){
            if(A[i] > A[i+1]) {
                return i;
            }
            i++;
        }
        return i;
    }
}
__________________________________________________________________________________________________
sample 38580 kb submission
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        for (int i = 1; i < A.length - 1; i++) {
            if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
                return i;
            }     
        }
        return -1;
    }
}
__________________________________________________________________________________________________
sample 38600 kb submission
class Solution {
    public int peakIndexInMountainArray(int[] A) {
        
        int maxVal = A[0],maxIn = 0;
        
        for(int i=1;i<A.length;i++){
            if(A[i]> maxVal){
                maxVal = A[i];
                maxIn = i;
            }
            else
                break;
        }
        
        return maxIn;
    }
}