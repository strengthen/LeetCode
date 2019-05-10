__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int largestRectangleArea(int[] heights) {
        return area(heights, 0, heights.length - 1);
    }
    
    private int area(int[] heights, int start, int end) {
        if (start > end) {
            return 0;
        }
        
        if (start == end) {
            return heights[start];
        }
        
        int min = heights[start];
        boolean sorted = true;
        
        for (int i = start + 1; i <= end; ++i) {
            min = min < heights[i] ? min : heights[i];
            
            if (heights[i - 1] > heights[i]) {
                sorted = false;
            }
        }
        
        if (sorted) {
            int max = 0;
            
            for (int i = start; i <= end; ++i) {
                max = Math.max(max, (end - i + 1) * heights[i]);
            }
            
            return max;
        }
        
        int area = min * (end - start + 1);
        int startIndex = start;
        
        for (int i = start; i <= end; ++i) {
            if (heights[i] == min) {
                area = Math.max(area, area(heights, startIndex, i - 1));
                startIndex = i + 1;
            }
        }
        
        return heights[end] != min ?
            Math.max(area, area(heights, startIndex, end)): area;
    }
}
__________________________________________________________________________________________________
sample 37240 kb submission
class Solution {
   
    class Node{
        int idx;
        int val;
        Node(int idx, int val){
            this.idx = idx;
            this.val = val;
        }
    }

    public int largestRectangleArea(int[] heights) {
        if(heights == null|| heights.length == 0)       return 0;
        int maxArea = 0;

        Stack<Node> stack = new Stack<>();

        for (int i = 0; i < heights.length; i++) {
            while(!stack.isEmpty() && stack.peek().val > heights[i]) {
                Node node = stack.pop();
                maxArea = Integer.max(maxArea, node.val * (i - (stack.isEmpty() ? 0 : stack.peek().idx + 1)));
            }
            stack.push(new Node(i, heights[i]));
        }

        if(stack.isEmpty())     return maxArea;

     //   System.out.println(stack);
        int rightBound = heights.length;

        while(!stack.isEmpty()){
            Node node = stack.pop();
            maxArea = Integer.max(maxArea, node.val * (rightBound - (stack.isEmpty() ? 0 : stack.peek().idx + 1)));
        }

        //last value in the stack will be smallest value in the whole array
        //maxArea = Integer.max(maxArea, node.val * (rightBound));

        return maxArea;
    }
}
__________________________________________________________________________________________________
