__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int matrixScore(int[][] A) {
        // flip the rows first
        for (int i = 0; i < A.length; i++) {
            if (A[i][0] == 0) {
                for (int j = 0; j < A[i].length; j++) {
                    if (A[i][j] == 0) {
                        A[i][j] = 1;
                    } else {
                        A[i][j] = 0;
                    }
                }
            }
        }
        
        // now all rows begin with 1, we can deal with columns
        
        for (int i = 1; i < A[0].length; i++) {
            int numOnes = 0;
            for (int j = 0; j < A.length; j++) {
                if (A[j][i] == 1) {
                    numOnes++;
                }
            }
            if (numOnes * 2 < A.length) {
                for (int j = 0; j < A.length; j++) {
                    if (A[j][i] == 1) {
                        A[j][i] = 0;
                    } else {
                        A[j][i] = 1;
                    }
                }
            }
        }
        
        // calculate the sum
        int sum = 0;
        for (int i = 0; i < A.length; i++) {
            int num = 0;
            for (int j = 0; j < A[i].length; j++) {
                num += A[i][j];
                num = num << 1;
            }
            num = num >> 1;
            sum += num;
        }
        return sum;
    }
}
__________________________________________________________________________________________________
sample 37720 kb submission
class Solution {
    public int matrixScore(int[][] A) {
        for(int i=0; i<A.length; i++){
            if(A[i][0] == 0){
                A = toggleRow(A, i);
            }
        }
        for(int i=0; i<A[0].length; i++){
            if(countOnesInCol(A, i) < (double)A.length/2){
                A = toggleCol(A, i);
            }
        }
        
        int score = 0;
        for(int i=0; i<A.length; i++){
            score += intArrToInt(A[i]);
        }
        return score;
    }
    
    public int[][] toggleCol(int[][] A, int colNum){
        for(int i=0; i<A.length; i++){
            A[i][colNum] = A[i][colNum] ^ 1;
        }
        return A;
    }
    
    public int[][] toggleRow(int[][] A, int rowNum){
        for(int i=0; i<A[rowNum].length; i++){
            A[rowNum][i] = A[rowNum][i] ^ 1;
        }
        return A;
    }
    
    public int countOnesInCol(int[][] A, int colNum){
        int count = 0;
        for(int i=0; i<A.length; i++){
            if(A[i][colNum] == 1){
                count++;
            }
        }
        return count;
    }
    
    public int intArrToInt(int[] nums){
        StringBuilder strNum = new StringBuilder();
        for (int num : nums) 
        {
             strNum.append(num);
        }
        return Integer.parseInt(strNum.toString(), 2);
    }
}
__________________________________________________________________________________________________
