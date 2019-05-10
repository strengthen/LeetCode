__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0) return false;
        int m=matrix.length, n=matrix[0].length;
        int i=0, j= m*n-1;
        while (i<=j) {
            int mid = i + (j-i)/2;
            int x = mid / n;
            int y = mid % n;
            if (matrix[x][y] == target) return true;
            if (matrix[x][y] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;                
            }
        }
        return false;
    }
}
__________________________________________________________________________________________________
sample 35376 kb submission
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int low;
        int high;
        int mid;
        if(matrix.length == 0) return false;
        for(int[] arr : matrix){
            if(arr.length == 0) continue;
            if(arr.length == 1 && arr[0] == target) return true;
            if(arr.length > 0 && target <= arr[arr.length-1]){
                 low = 0;
                 high = arr.length - 1;
                while(low <= high){
                    mid = (high - low) + low / 2;
                    if(arr[mid] < target)
                        low = mid + 1;
                    else if (arr[mid] > target)
                        high = mid - 1;
                    else if(arr[mid] == target)
                        return true;                
                }
                return false;
            }
          }
        return false;
    }
}
__________________________________________________________________________________________________
