__________________________________________________________________________________________________
sample 98 ms submission
class MedianFinder {
    TreeNode head;

    /** initialize your data structure here. */
    public MedianFinder() {
        
    }
    
    public void addNum(int num) {
        if (this.head == null) {
            this.head = new TreeNode(num, 1, 0, 0);
            return;
        }
        
        TreeNode current = this.head;
        while (current != null) {
            if (num == current.value) {
                current.count++;
                return;
            } else if (num < current.value) {
                current.leftNodes++;
                if (current.left == null) {
                    current.left = new TreeNode(num, 1, 0, 0);
                    return;
                }
                
                current = current.left;
            } else {
                current.rightNodes++;
                if (current.right == null) {
                    current.right = new TreeNode(num, 1, 0, 0);
                    return;
                }
                
                current = current.right;
            }
        }
    }
    
    public double findMedian() {
        if (this.head == null) {
            return Double.MIN_VALUE; // Invalid
        }
        
        TreeNode current = this.head;
        int lowers = 0;
        int highers = 0;
        while (current != null) {
            if (current.count > Math.abs((current.leftNodes + lowers) - (current.rightNodes + highers))) {
                return (double) current.value;
            } else if (current.count == Math.abs((current.leftNodes + lowers) - (current.rightNodes + highers))) {
                if ((current.leftNodes + lowers) > (current.rightNodes + highers)) {
                    return (double) (current.value + this.rightMost(current.left).value) / 2;
                } else {
                    return (double) (current.value + this.leftMost(current.right).value) / 2;
                }
            } else if ((current.leftNodes + lowers) > (current.rightNodes + highers)) {
                highers += current.count + current.rightNodes;
                current = current.left;
            } else {
                lowers += current.count + current.leftNodes;
                current = current.right;
            }
        }
        
        return Double.MIN_VALUE; // Invalid
    }
    
    private TreeNode leftMost(TreeNode node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }
    
    private TreeNode rightMost(TreeNode node) {
        while (node.right != null) {
            node = node.right;
        }
        return node;
    }
    
    private class TreeNode {
        public int value;
        public int count;
        public int leftNodes;
        public int rightNodes;
        public TreeNode left;
        public TreeNode right;
        
        public TreeNode(int value, int count, int leftNodes, int rightNodes) {
            this.value = value;
            this.count = count;
            this.leftNodes = leftNodes;
            this.rightNodes = rightNodes;
        }
    }
}

//1256333493

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
__________________________________________________________________________________________________
sample 50468 kb submission
class MedianFinder {

    /** initialize your data structure here. */
    PriorityQueue<Integer> maxHeap;
    PriorityQueue<Integer> minHeap;
    
    public MedianFinder() {
        maxHeap = new PriorityQueue<Integer>((a,b)->(b-a));
        minHeap = new PriorityQueue<Integer>();
    }
    
    public void addNum(int num) {
        if (maxHeap.size() == 0 || maxHeap.peek()>num) {
            maxHeap.offer(num);
        } else {
            minHeap.offer(num);
        }
        if (Math.abs(maxHeap.size()-minHeap.size())>1) {
            rebalance(maxHeap, minHeap);
        }
    }
    
    private void rebalance(PriorityQueue<Integer> maxHeap, PriorityQueue<Integer> minHeap) {
        PriorityQueue<Integer> large = maxHeap.size()>minHeap.size()? maxHeap: minHeap;
        PriorityQueue<Integer> small = minHeap.size()<maxHeap.size()? minHeap: maxHeap;
        small.offer(large.poll());
    }
    
    public double findMedian() {
        PriorityQueue<Integer> large = maxHeap.size()>minHeap.size()? maxHeap: minHeap;
        PriorityQueue<Integer> small = minHeap.size()<maxHeap.size()? minHeap: maxHeap;
        if (large.size() == small.size()) {
            return (double) (large.peek() + small.peek())/2;
        } else {
            return large.peek();
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
__________________________________________________________________________________________________
