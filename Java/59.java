__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];

        int value = 1;

        for (int level = 0; level < (n + 1) / 2; level++) {
            for (int i = level; i < n - level; i++) {
                res[level][i] = value++;
            }
            for (int j = level + 1; j < n - level - 1; j++) {
                res[j][n - 1 - level] = value++;
            }

            if (level != n - level - 1) {
                for (int k = n - level - 1; k >= level; k--) {
                    res[n - level - 1][k] = value++;
                }
                for (int l = n - level - 2; l > level; l--) {
                    res[l][level] = value++;
                }
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 36624 kb submission
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        int rowStart = 0;
        int rowEnd = n - 1;
        int colStart = 0;
        int colEnd = n - 1;
        int count = 1;
        while(rowStart <= rowEnd && colStart <= colEnd) {
            for(int i = colStart ; i <= colEnd ; i++)
                result[rowStart][i] = count++;
            rowStart++;
            for(int i = rowStart ; i <= rowEnd ; i++)
                result[i][colEnd] = count++;
            colEnd--;
            for(int i = colEnd ; i >= colStart ; i--) {
                if(rowStart <= rowEnd)
                    result[rowEnd][i] = count++;
            }
            rowEnd--;
            for(int i = rowEnd ; i >= rowStart ; i--) {
                if(colStart <= colEnd)
                    result[i][colStart] = count++;
            }
            colStart++;
        }
        return result;
    }
}
__________________________________________________________________________________________________
