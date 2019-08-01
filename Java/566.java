__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int or = nums.length;
        int oc = nums[0].length;
        
        if(or * oc != r * c) {
            return nums;
        }
        
        int[][] newMatrix = new int[r][c];
        
        for(int k = 0; k < r * c; k++) {
            // Just test the index conversion here.
            newMatrix[k / c][k % c] = nums[k / oc][k % oc];
        }
        
        return newMatrix;
    }
}
__________________________________________________________________________________________________
sample 39084 kb submission
public class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int[][] res = new int[r][c];
        if (nums.length == 0 || r * c != nums.length * nums[0].length)
            return nums;
        int count = 0;
        Queue < Integer > queue = new LinkedList < > ();
        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums[0].length; j++) {
                queue.add(nums[i][j]);
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res[i][j] = queue.remove();
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
