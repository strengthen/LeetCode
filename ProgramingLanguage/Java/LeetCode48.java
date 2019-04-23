__________________________________________________________________________________________________
0ms
class Solution {
    public void rotate(int[][] matrix) {
        int n =  matrix.length;
        for(int i=0; i<n/2; i++){
            for(int j=i; j<n-1-i; j++){
                int tmp = matrix[j][n-1-i];
                matrix[j][n-1-i] = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = tmp;
            }
        }
    }
}
__________________________________________________________________________________________________
0ms
class Solution {
    public void rotate(int[][] matrix) {
        // Reverse
        for (int i = 0; i < matrix.length / 2; i++) {
            int j = matrix.length - 1 - i;
            int[] cache = matrix[i];
            matrix[i] = matrix[j];
            matrix[j] = cache;
        }
        // Transpose
        for (int i = 0; i < matrix.length; i++) {
            for (int j = i + 1; j < matrix.length; j++) {
                int cache = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = cache;
            }
        }
    }
}
__________________________________________________________________________________________________
1ms
class Solution {
    
    public void rotate(int[][] matrix) {
        if ( matrix != null ) {
            
            int currentX;
            int currentY;
            int previous;
            int nextDirection;
            
            for(int rotatedFrameIndex = 0; rotatedFrameIndex <= matrix.length/2; ++rotatedFrameIndex) {
                int frameSize = matrix.length - rotatedFrameIndex * 2;
                if ( frameSize <= 1 ) {
                    break;
                }
                
                
                for(int t = 0; t < frameSize  - 1; ++t) {
                    previous = matrix[rotatedFrameIndex + 1][rotatedFrameIndex];
        
                    currentX = rotatedFrameIndex;
                    currentY = rotatedFrameIndex;

                    nextDirection = 1;

                    for(int i = 0; i < frameSize * 4 - 4; ++i) {

                        if ( ( i > 0 ) && ( i % ( frameSize - 1 ) == 0 ) ) {
                            ++nextDirection;
                        }

                        int tmp = matrix[currentY][currentX];
                        matrix[currentY][currentX] = previous;
                        previous = tmp;

                        switch(nextDirection) {
                            case 1: ++currentX; break;
                            case 2: ++currentY; break;
                            case 3: --currentX; break;
                            case 4: --currentY; break;
                        }
                    }
                }
            }
        }
    }
}
__________________________________________________________________________________________________
34672 kb
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int iMax = n/2 + (n % 2 == 1? 1 : 0);
        int temp = 0;
        for (int i = 0; i < iMax; i++) {
            for (int j = i; j < n-i-1; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = temp;
            }
        }
    }
}
__________________________________________________________________________________________________
34700 kb
class Solution {
    public void rotate(int[][] matrix) {
        if(matrix==null || matrix.length==0) return;
        int len = matrix.length;
        for(int i=0; i<=(len-1)/2; i++){
            helper(matrix, i, i, len-2*i);
        }
        return;
               
    }
    public void helper(int[][] matrix, int start_i, int start_j, int len){
        if(len<=1) return;
        for(int i=start_i; i<start_i+len-1; i++){
            int temp = matrix[i][start_j];
            matrix[i][start_j] = matrix[start_i+len-1][i];
            matrix[start_i+len-1][i] = matrix[2*start_i+len-1-i][start_j+len-1];
            matrix[2*start_i+len-1-i][start_j+len-1] = matrix[start_i][2*start_j+len-1-i];
            matrix[start_i][2*start_j+len-1-i] = temp;          
        }
        return;
    }
}
__________________________________________________________________________________________________