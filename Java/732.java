__________________________________________________________________________________________________
sample 51 ms submission
class MyCalendarThree {

   
    
    class TreeNode {
        public int start;
        public int end;
        public int count;
        public TreeNode left = null;
        public TreeNode right = null;
        public TreeNode(int start, int end, int count) {
            this.start = start;
            this.end = end;
            this.count = count;
            
        }
    }
    
    int max;
    TreeNode root;
    
    
    public MyCalendarThree() {
        this.max = 0;
        this.root = new TreeNode(0, (int)Math.pow(10,9), 0);
        
    }
    
    public int book(int start, int end) {
        update(root, start, end);
        return max;
    }
    
    private void update(TreeNode current, int start, int end) {
        // interval matches perfectly this is the base case
        if(start == current.start && end == current.end) {
            current.count++;
            max = Math.max(max, current.count);
            if(current.left == null && current.right == null) return; 
        }
        
        // this is where new children are created
        // begin checking if there even exists any children
        if(current.left == null && current.right == null) {
            // if the new interval is left aligned but doesn't match end (checked in base case)
            // this check is basically nessecary to check how to split the different new intervals
            // (should the right begin with the start or end of the new interval)
            if(current.start == start) {
                current.left = new TreeNode(current.start, end, current.count);
                current.right = new TreeNode(end, current.end, current.count);
                // recusivly update left tree since it's a left align interval
                update(current.left, start, end);
            } else {
                current.left = new TreeNode(current.start, start, current.count);
                current.right = new TreeNode(start, current.end, current.count);
                update(current.right, start, end);
            }
            
        // the two first if statements checks if the new interval is completley within 
        // one of the current children else we have to update both
        } else if(current.right.start <= start) {
            update(current.right, start, end);
        } else if(end <= current.left.end) {
            update(current.left, start, end);
        } else {
            update(current.left, start, current.left.end);
            update(current.right, current.right.start, end);
        }        
    }
}

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
__________________________________________________________________________________________________
sample 38952 kb submission
class MyCalendarThree {
    TreeMap<Integer, Integer> map;
    public MyCalendarThree() {
        map = new TreeMap<>();
    }
    
    public int book(int start, int end) {
        map.put(start, map.getOrDefault(start, 0) + 1);
        map.put(end, map.getOrDefault(end, 0) - 1);
        
        int curr = 0, ans = 0;
        for(int i : map.values()) {
            curr += i;
            ans = Math.max(ans, curr);
        }
        return ans;
    }
}

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
__________________________________________________________________________________________________
