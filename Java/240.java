__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if(matrix==null || matrix.length==0 || matrix[0].length==0)return false;
        int x=matrix.length-1, y=matrix[0].length-1;
        if(target <matrix[0][0] || target >matrix[x][y])
            return false;
        y=0;
        while(target!=matrix[x][y]){
            if(target < matrix[x][y])x--;
            else y++;
            if(x<0 || y>=matrix[0].length)return false;  
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 41320 kb submission
class Solution {
    // just a note: a binary search on a bigger collection/array is more efficient than splitting the array into multiple parts and running binary search on them each.
    // i.e. if we were to split an array into 2 and run binary search on both sub-arrays,
    // the time complexity would be 2 * log(n/2)
    // if we ran binary search on the whole array.. that would just be log(n). More efficient.
    // this is just log(n/2) + 1 (where 1 = log 2). + 1 is better than * 2
    /// ofcourse this ia theoretical example. practically we would just check start/end of both subarrays to see if the element could eve possible exist in the array at all...
    
    // runtime is min(M,N) * log(max(M,N))
    // we'll just use N to represent the smaller one for the math.
    // this is the better algorithm when M and N differ by a lot.
    // there is a O(M + N ) algorithm too
    // that is only optmal when M + N < N log (M)
    // => M / log (M/2) < N , where N is <= M
    
    // graph on desmos:
    // \frac{x}{\left(\frac{\log\left(\frac{x}{2}\right)}{\log\left(2\right)}\right)}
    // x
    // N must be between these two curves
    // i.e. M / log (M/2) < N <= M
    
    public boolean searchMatrix(int[][] matrix, int target) {        
        if(matrix == null || matrix.length == 0) return false;
        
        int r = matrix.length;
        int c = matrix[0].length;
        
        double N = Math.min(r, c);
        double M = Math.max(r,c);
        
        return M / logBase2(M/2) < N ? searchMatrixAlg2(matrix, target) : searchMatrixAlg1(matrix, target);
    }
    
    public double logBase2(double n) {
        return Math.log(n) / Math.log(2);
    }
    
    public boolean searchMatrixAlg2(int[][] matrix, int target) {
        if(matrix == null || matrix.length < 1 || matrix[0].length <1) {
            return false;
        }
        int col = matrix[0].length-1;
        int row = 0;
        while(col >= 0 && row <= matrix.length-1) {
            if(target == matrix[row][col]) {
                return true;
            } else if(target < matrix[row][col]) {
                col--;
            } else if(target > matrix[row][col]) {
                row++;
            }
        }
        return false;
    }
    
    // O(n*logm)
    public boolean searchMatrixAlg1(int[][] matrix, int target) {
        if(matrix == null || matrix.length == 0) return false;
        
        int r = matrix.length;
        int c = matrix[0].length;
        
        if(c >= r) {
            return searchRowWise(matrix, target, r, c);
        }
        else {
            return searchColumnWise(matrix, target, r, c);
        }
    }
    
    private boolean searchRowWise(int[][] matrix, int target, int numRows, int numCols) {
        for(int row = 0; row < numRows; row++) {
            if(binarySearchRows(matrix[row], target, 0, numCols - 1)) {
                return true;
            }
        }
        return false;
    }
    
    private boolean searchColumnWise(int[][] matrix, int target, int numRows, int numCols) {
        for(int col = 0; col < numCols; col++) {
            if(binarySearchCols(matrix, col, target, 0, numRows - 1)) {
                return true;
            }
        }
        return false;
    }
    
    private boolean binarySearchRows(int[] arr, int target, int start, int end) {
        if(start > end) {
            return false;
        }
        int mid = (start + end) / 2;
        if(target == arr[mid]) {
            return true;
        }
        if(target < arr[mid]) {
            return binarySearchRows(arr, target, start, mid - 1);
        }
        return binarySearchRows(arr, target, mid + 1, end);
    }
    
    private boolean binarySearchCols(int[][] matrix, int col, int target, int start, int end) {
        if(start > end) {
            return false;
        }
        int mid = (start + end) / 2;
        if(target == matrix[mid][col]) {
            return true;
        }
        if(target < matrix[mid][col]) {
            return binarySearchCols(matrix, col, target, start, mid - 1);
        }
        return binarySearchCols(matrix, col, target, mid + 1, end);
    }
}
__________________________________________________________________________________________________
