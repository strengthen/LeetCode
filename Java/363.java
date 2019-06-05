__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        // assume there are more rows than columns
        int m = matrix.length, n = matrix[0].length, res = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            int[] sum = new int[m];
            for (int c = i; c < n; c++) {
                for (int r = 0; r < m; r++) {
                    sum[r] += matrix[r][c];
                }
                int max = sum[0], maxSoFar = 0;
                for (int s : sum) {
                    maxSoFar = Math.max(maxSoFar + s, s);
                    max = Math.max(max, maxSoFar);
                }
                if (max == k) return k;
                if (max < k) res = Math.max(res, max);
                else {
                    for (int r = 0; r < m; r++) {
                        int currSum = 0;
                        for (int row = r; row < m; row++) {
                            currSum += sum[row];
                            if (currSum <= k) res = Math.max(res, currSum);
                        }
                    }
                }
                if (res == k) return res;
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 35296 kb submission
class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int row = matrix.length;
        int col = matrix[0].length;
        int result = Integer.MIN_VALUE;
        for (int i = 0; i < col; i ++) {
            int[] rowSum = new int[row];
            for (int j = i; j < col; j ++) {
                int sum = 0;
                int max = Integer.MIN_VALUE;
                for (int r = 0; r < row; r ++) {
                    rowSum[r] += matrix[r][j];
                    if (sum < 0)
                        sum = 0;
                    sum += rowSum[r];
                    max = max > sum ? max : sum;
                }
                if (max <= k) {
                    result = result > max ? result : max;
                } else {
                    max = Integer.MIN_VALUE;
                    for (int m = 0; m < row; m ++) {
                        sum = 0;
                        for (int n = m; n < row; n ++) {
                            sum += rowSum[n];
                            if (sum <= k)
                                max = max > sum ? max : sum;
                        }
                    }
                    result = result > max ? result : max;
                }
                if (result == k)
                    return k;
            }
        }
        return result; 
    }
}
__________________________________________________________________________________________________
