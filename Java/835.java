__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int largestOverlap(int[][] A, int[][] B) {
        int size = A.length;
        int maxOverlap = 0;
        
        // shift A first
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int overlap = calcOverlap(A, B, i, j);
                maxOverlap = Math.max(overlap, maxOverlap);
            }
        }
        
        // then shift B
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int overlap = calcOverlap(B, A, i, j);
                maxOverlap = Math.max(overlap, maxOverlap);
            }
        }
        return maxOverlap;
    }
    
    private int calcOverlap(int[][] A, int[][] B, int shiftX, int shiftY) {
        int len = A.length;
        int overlap = 0;
        
        for (int i = shiftY; i < len; i++) {
            for (int j = shiftX; j < len; j++) {
                overlap += A[i - shiftY][j - shiftX] * B[i][j];
            }
        }
        return overlap;
    }
}
__________________________________________________________________________________________________
sample 37388 kb submission
class Solution {
    public int largestOverlap(int[][] A, int[][] B) {
        int N = A.length;
        int[][] count = new int[2*N+1][2*N+1];
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (A[i][j] == 1)
                    for (int i2 = 0; i2 < N; ++i2)
                        for (int j2 = 0; j2 < N; ++j2)
                            if (B[i2][j2] == 1)
                                count[i-i2 +N][j-j2 +N] += 1;

        int ans = 0;
        for (int[] row: count)
            for (int v: row)
                ans = Math.max(ans, v);
        return ans;
    }
}
__________________________________________________________________________________________________
