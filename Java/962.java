__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int maxWidthRamp(int[] A) {
        int n = A.length;
        if(n==0){
            return 0;
        }

        int[] leftCandidate = new int[n]; // all "possible" left indexes
        int[] rightCandidate = new int[n]; // all "possible" right indexes


        int currentLeft = 50001; // all elements in the range [0,50_000]. We want to ensure considering index = 0
        int counter1 = 0;
        for(int i=0;i<n;i++){
            if(A[i]<currentLeft){
                leftCandidate[counter1] = i;
                currentLeft = A[i];
                counter1++;
            }
        }
        int n1 = counter1;


        int counter2 = 0;
        int currentRight = -1; // all elements in the range [0,50_000]. We want to ensure considering index = n-1.
        for(int i =n-1;i>=0;i--){
            if(A[i]>currentRight) {
                rightCandidate[counter2] = i;
                currentRight = A[i];
                counter2++;
            }
        }
        int n2 = counter2;






        int maxSolution = 0;
        int j = n2-1;

        for(int i=0;i<n1;i++){
            while(j >=0 && A[rightCandidate[j]]>=A[leftCandidate[i]]){
                j--; // try to advance j
            }
            j++; // we advanced j one step one step "too much".
            maxSolution = Math.max(maxSolution,rightCandidate[j]-leftCandidate[i]);
        }

        return maxSolution;
    }
}
__________________________________________________________________________________________________
sample 46488 kb submission
class Solution {
    public int maxWidthRamp(int[] A) {
        if (A == null || A.length == 0) {
            return 0;
        } 
        
        Integer[] sortedIndices = new Integer[A.length];
        for (int i = 0; i < A.length; i++) {
            sortedIndices[i] = i;
        }
        
        Arrays.sort(sortedIndices, (i, j) -> ((Integer) A[i]).compareTo(A[j]));
        
        for (int i = 0; i < A.length; i++) {
            System.out.print(sortedIndices[i] + " ");
        }
        
        int min = sortedIndices[0];
        int ramp = 0;
        
        for (int i = 1; i < sortedIndices.length; i++) {
            ramp = Math.max(ramp, sortedIndices[i] - min);
            min = Math.min(min, sortedIndices[i]);
        }
        
        return ramp;
    }
}
__________________________________________________________________________________________________
