__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int maxUncrossedLines(int[] A, int[] B) {
        int[] dp = new int[B.length];
    
        int maxCount = 0;
        
        for(int i = 0 ; i < A.length ; i++){            
            int prevCount = 0;
            for(int j = 0 ; j < B.length ; j++){                
                int temp = dp[j];
                if(A[i] == B[j]){
                    dp[j] = prevCount + 1;
                    maxCount = Math.max(maxCount, dp[j]);
                }
                prevCount = Math.max(temp, prevCount);
            }
        }
        
        
        return maxCount;
    }
}
__________________________________________________________________________________________________
sample 34540 kb submission
class Solution {
    public int maxUncrossedLines(int[] A, int[] B) {
        int[][] editDistance = new int[A.length + 1][B.length + 1];
        IntStream.range(0, A.length + 1).forEach(i -> editDistance[i][0] = i);
        IntStream.range(0, B.length + 1).forEach(i -> editDistance[0][i] = i);
        for (int i = 1; i <= A.length; i++) {
            for (int j = 1; j <= B.length; j++) {
                editDistance[i][j] = editDistance[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 0 : 2);
                editDistance[i][j] = Math.min(editDistance[i][j], editDistance[i - 1][j] + 1);
                editDistance[i][j] = Math.min(editDistance[i][j], editDistance[i][j - 1] + 1);
            }
        }
        return (A.length + B.length - editDistance[A.length][B.length]) / 2;
    }
}
__________________________________________________________________________________________________
