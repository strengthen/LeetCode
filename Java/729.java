__________________________________________________________________________________________________
sample 51 ms submission
class MyCalendar {

    public MyCalendar() {
        
    }
    
    private Node root;
    
    public boolean book(int start, int end) {
        if(root==null) {
            root=new Node(start,end);
            return true;
        }
        return add(root,start,end,Integer.MIN_VALUE,Integer.MAX_VALUE);
        
    }
    
    private boolean add(Node node, int start, int end, int min, int max) { //end can be max, start can be min
        int v_s=node.start;
        int v_e=node.end;
        if(start<min ||end<min || start>max|| end>max) {return false;}
        if(end<=v_s) {
            if(node.left==null) {
                node.left=new Node(start,end);
                return true;
            } else {
                return add(node.left,start,end,min,v_s);
            }
        } else if(start>=v_e) {
            if(node.right==null) {
                node.right=new Node(start,end);
                return true;
            } else {
                return add(node.right,start,end,v_e,max);
            }
        } else {
            return false;
        }
    }
    
    class Node {
        int start;
        int end;
        Node left;
        Node right;
        Node(int s, int e) {
            start=s;
            end=e;
        }
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
__________________________________________________________________________________________________
sample 36232 kb submission
class MyCalendar {
    List<int[]> booking = new ArrayList<>();
    public boolean book(int start, int end) {
        for (int[] b : booking) {
            if (Math.max(b[0], start) < Math.min(b[1], end)) return false;
        }
        booking.add(new int[]{start, end});
        return true;
    }
}
__________________________________________________________________________________________________
