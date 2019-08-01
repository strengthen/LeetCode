__________________________________________________________________________________________________
sample 63 ms submission
class Solution {
    Map<Integer, Integer> map = new HashMap();
    int rows, cols, total;
    Random rand;
    public Solution(int n_rows, int n_cols) {
        rows = n_rows;
        cols = n_cols;
        total = rows * cols;
        rand = new Random();
    }
    
    public int[] flip() {
        int index = rand.nextInt(total--);
        
        //check这个index之前有没有被flip过
        int realIndex = map.getOrDefault(index, index);
        
        map.put(index, map.getOrDefault(total, total));
        
        return new int[]{realIndex / cols, realIndex  % cols};
    }
    
    public void reset() {
        map.clear();
        total = rows * cols;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * int[] param_1 = obj.flip();
 * obj.reset();
 */
__________________________________________________________________________________________________
sample 35916 kb submission
class Solution {

    Map<Integer, Integer> list;
    int r, c;
    int total;
    
    public Solution(int n_rows, int n_cols) {
        r = n_rows;
        c = n_cols;
        total = r*c;
        list = new HashMap();

    }
    
    public int[] flip() {
        int pos, idx;
        if(total == 1) idx = 0;
        else {
            idx =(int)(Math.random()*total);
            //if(idx > total) idx = total;
        }
        
        pos = list.getOrDefault(idx, idx);
        list.put(idx, list.getOrDefault(total-1,total-1));
        list.put(total-1, pos);
        total--;
        int[] res = new int[] {pos/c, pos%c};
        return res;
        
    }
    
    public void reset() {
        total = r*c;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * int[] param_1 = obj.flip();
 * obj.reset();
 */
__________________________________________________________________________________________________
