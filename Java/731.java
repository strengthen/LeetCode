__________________________________________________________________________________________________
sample 59 ms submission
class MyCalendarTwo {
    private Node root;
    public MyCalendarTwo() {
        root = new Node(-2, -1);
    }
    
    public boolean book(int start, int end) {
        if(!root.canInsert2(start, end)){
            return false;
        }
        insert(start, end, root);
        return true;
    }
    
    static class Node{
        Node left;
        Node right;
        int start;
        int end;
        int count;
        
        Node(int start, int end){
            this.start = start;
            this.end = end;
            this.count = 1;
        }
        
        boolean canInsert2(int start, int end){
            if(start >= end){
                return true;
            }
            if(end <= this.start){
                return this.left == null || this.left.canInsert2(start, end);
            } else if(start >= this.end){
                return this.right == null || this.right.canInsert2(start, end);
            } else{
                //System.out.println(this.start + "#" + this.end + ":" + start + "#" + end);
                return count<2 && (this.left == null || this.left.canInsert2(start, Math.min(this.start, end))) && (this.right == null || this.right.canInsert2(Math.max(this.end, start), end));
            }
        }
    }
    
    public static Node insert(int start, int end, Node nodeToInsert){
        if(start >= end){
            return nodeToInsert;
        }
        if(nodeToInsert == null){
            return new Node(start, end);
        }
        if(end <= nodeToInsert.start){
            nodeToInsert.left = insert(start, end, nodeToInsert.left);
        } else if(start >= nodeToInsert.end){
            nodeToInsert.right = insert(start, end, nodeToInsert.right);
        } else {
            int newStart = Math.max(start, nodeToInsert.start);
            int newEnd = Math.min(end, nodeToInsert.end);
            
            nodeToInsert.left = insert(Math.min(start, nodeToInsert.start), newStart, nodeToInsert.left);
            nodeToInsert.right = insert(newEnd, Math.max(end, nodeToInsert.end), nodeToInsert.right);
            
            nodeToInsert.count++;
            nodeToInsert.start = newStart;
            nodeToInsert.end = newEnd;
        }
        return nodeToInsert;
    }
}
__________________________________________________________________________________________________
sample 38068 kb submission
// import java.util.Comparator;
import java.util.TreeSet;
class MyCalendarTwo {
    List<int[]> bookings;
    List<int[]> overlapped;
    public MyCalendarTwo() {
        bookings = new ArrayList<int[]>();
        overlapped = new ArrayList<int[]>();
    }
    
    public boolean book(int start, int end) {
        for (int[] e : bookings) {
            int overlapped_start = Math.max(e[0], start);
            int overlapped_end = Math.min(e[1], end);
            if (overlapped_start < overlapped_end) {  //overlapped
                for (int[] o : overlapped) {
                    if (Math.max(o[0], overlapped_start) < Math.min(o[1], overlapped_end)) {
                        overlapped.clear();
                        return false;
                    }
                }
                overlapped.add(new int[] {overlapped_start, overlapped_end});
            }
        }
        bookings.add(new int[] {start, end});
        return true;
        
    }
    
   
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */
__________________________________________________________________________________________________
