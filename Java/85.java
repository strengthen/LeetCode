__________________________________________________________________________________________________
sample 3 ms submission
/*
    The basic idea is to scan the matrix row by row and find out three things: 
    - what's the maximum height from this point going upwards
    - what's the left boundary from this point looking left given that the previous row's left boundary is equal or further left compare to current row's left boundary (So this is where the DP comes in, you current small step is ONLY based on the previous step)
    - what's the right boundary from this point looking right given that the previous row's left boundary is equal or further right compare to current row's right boundary
    
    
    with these three information, we can calcualte the rectangle we can form if we explore from current block upwards, left and right. We use a variable to keep updating the maxarea and the final resutls will be the result we need. 

*/

class Solution {

    public int maximalRectangle(char[][] matrix) {
        if(matrix.length == 0) return 0;
        int m = matrix.length; // depth of matrix
        int n = matrix[0].length; // width of matrix

        // initial 3 dp arrays to keep track of states. 
        int[] left = new int[n]; 
        int[] right = new int[n];
        int[] height = new int[n];

        // initialize 'right' as the rightmost boundary possible because we are check from the right. 
        Arrays.fill(right, n);

        int maxarea = 0;
        // iterate each row
        for(int i = 0; i < m; i++) {
            // initialize the cur_left boundary to be 0, and right to be the rightmost. 
            int cur_left = 0, cur_right = n;
            // update height, at each vertical point j.  Height is basically from this point[i][j] looking up, what's the highest we can reach, and when we encounter a 0 at current row, we reset the height, because the one below this can only see 0 which is a block.
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            // update left 
            for(int j=0; j<n; j++) {
                /*
                This is the DP transition function. Which is not very obvious what's the n-1 step
                because the n-1 here is previous row, but previous row here IMPLICIT because we scan row by row.
                
                Here we are basically compare the cur_left from this row with the furtherst left we can go on the previous row.
                We can either have this: 
                            01110
                          ->00110
                or this: 
                            00110
                          ->01110
                or they are equal length.
                
                if we encounter a 0, then the left boundary left[j] becomes 0 because we encountered a block,
                and the cur_left is set to one position to the right of current index which is just temp update
                assuming next number will be 1, but if not, then we just keep updating cur_left until we see a 1.
                
                So basically: 
                - cur_left is what's the left boundary from current position looking left. 
                - left[j] is what's the left boundary if we take previous row into consideration. 
                
                */
                if(matrix[i][j]=='1') left[j]=Math.max(left[j],cur_left);
                else {left[j]=0; cur_left=j+1;} 
            }
            // update right. The whole idea is similar to how we update the left
            // but why can we rest right[j] to n?? wouldn't that skew the result when we do right -left
            // oh ok it doesn't matter because height will be zero
            for(int j = n - 1; j >= 0; j--) {
                if(matrix[i][j] == '1') right[j] = Math.min(right[j], cur_right);
                else {right[j] = n; cur_right = j;}    
            }
            // update area based on the information from each row. 
            for(int j = 0; j < n; j++) {
                if (matrix[i][j]=='1')
                    maxarea = Math.max(maxarea, (right[j] - left[j]) * height[j]);
            }
        }
        return maxarea;
    }
}
__________________________________________________________________________________________________
sample 36792 kb submission
class Solution {
    private int largestRectangleArea(int[] heights){
        int max = 0;
        Deque<int[]> stack = new LinkedList<>();
        for(int i = 0; i < heights.length; ++i){
            int[] top = new int[]{i, heights[i]};
            while(!stack.isEmpty() && stack.peekLast()[1] >= top[1]){
                int[] end = stack.pollLast();
                int area = end[1] * (i - end[0]);
                max = Math.max(max, area);
                top[0] = end[0];
            }
            stack.add(top);
        }
        
        while(!stack.isEmpty()){
            int[] front = stack.pollFirst();
            int area = front[1] * (heights.length - front[0]);
            max = Math.max(max, area);
        }
        return max;
    }
    
    public int maximalRectangle(char[][] matrix) {
        int depth = matrix.length;
        int width = (depth > 0)? matrix[0].length: 0;
        int[] heights = new int[width];
        int max = 0;
        for(int y = 0; y < depth; ++y){
            for(int x = 0; x < width; ++x){
                heights[x] = (matrix[y][x] == '0')? 0: heights[x] + 1; 
            }
            max = Math.max(max, largestRectangleArea(heights));
        }
        return max;
    }
}
__________________________________________________________________________________________________
