__________________________________________________________________________________________________
sample 101 ms submission
class Solution {

    private int[] sum;
    private int[][] rects;
    private Random rand = new Random();		

    public Solution(int[][] rects) {
        this.rects = rects;	    	
        this.sum = new int[rects.length];
        for (int i = 0;i < rects.length;i ++) {
            sum[i] = getSum(rects[i]);	    		
            if (i > 0) {
                sum[i] += sum[i - 1];	    			
            }	    		
        }
    }

    public int[] pick() {
        int index = rand.nextInt(this.sum[this.sum.length - 1]) + 1;	    	
        int low = 0 , high = sum.length;
        while (low < high) {
            int mid = (low + high) / 2;	    		
            if (sum[mid] < index) {
                low = mid + 1;
            } else {
                high = mid;	    			
            }
        }
        int rectIndex = low;
        int[] rect = this.rects[rectIndex];
        int x1 = rect[0] , y1 = rect[1] , x2 = rect[2] , y2 = rect[3];	    	
        if (low - 1 >= 0) {
            index -= sum[low - 1];	    		
        }	    	
        int row = x2 - x1 + 1 , col = y2 - y1 + 1;
        int x = (index - 1) / col;
        int y = (index - 1) % col;	    
        return new int[] {x1 + x , y1 + y};	    
    }

    private int getSum(int[] rect) {
        int x1 = rect[0] , y1 = rect[1] , x2 = rect[2] , y2 = rect[3];
        return (x2 - x1 + 1) * (y2 - y1 + 1);	    	
    }

}
__________________________________________________________________________________________________
sample 46004 kb submission
class Solution {

    int rect[][];
    Random rand;
    int sum = 0;
    TreeMap<Integer, Integer> map;
    public Solution(int[][] rects) {
        rect = rects;
        rand = new Random();
        map = new TreeMap<>();
        for(int i=0; i<rect.length; i++){
            sum += (rect[i][2] - rect[i][0] + 1) * (rect[i][3] - rect[i][1] + 1);
            map.put(sum, i);
        }
    }
    
    public int[] pick() {
        int r = map.ceilingKey(rand.nextInt(sum+1));
        r = map.get(r);
        int x = rand.nextInt(rect[r][2] - rect[r][0] + 1) + rect[r][0];
        int y = rand.nextInt(rect[r][3] - rect[r][1] + 1) + rect[r][1];
        return new int[]{x,y};
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * int[] param_1 = obj.pick();
 */
__________________________________________________________________________________________________
