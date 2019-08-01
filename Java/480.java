__________________________________________________________________________________________________
sample 7 ms submission
/*
 * @lc app=leetcode id=480 lang=java
 *  2 treemap 52%(32ms)
 * 
 * [480] Sliding Window Median
 */
class Solution {
    //*
    class Node {
        int val;
        int count;
        int leftCount;
        Node left;
        Node right;
        public Node(int v) {
            val = v;
        }
    }

    public void add(Node n, int x) {
        if (x == n.val) {
            ++n.count;
        } else if (x < n.val) {
            n.leftCount++;
            if (n.left == null) n.left = new Node(x);
            add(n.left, x);
        } else {
            if (n.right == null) n.right = new Node(x);
            add(n.right, x);
        }
    }

    public void remove(Node n, int x) {
        if (x == n.val) {
            --n.count;
        } else if (x < n.val) {
            --n.leftCount;
            remove(n.left, x);
        } else {
            remove(n.right, x);
        }
    }

    public int getValue(Node n, int i) {
        return i < n.leftCount ? getValue(n.left, i)
             : i >= n.leftCount + n.count ? getValue(n.right, i-n.leftCount-n.count) 
             : n.val;
    }
    
    public double[] medianSlidingWindow(int[] nums, int k) {
        double[] res = new double[nums.length - k + 1];
        Node root = new Node(0);
        for (int i = 0; i < nums.length; ++i) {
            if (i >= k) {
                remove(root, nums[i-k]);
            }
            add(root, nums[i]);
            if (i >= k-1) {
                res[i-k+1] = k % 2 == 0
                    ? ((double)getValue(root, k/2) + getValue(root, (k-1)/2)) / 2
                    : (double)getValue(root, k/2);
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
sample 38732 kb submission
class Solution {
    // can use 2 treeset, and store the index to avoid duplicate values, (multiset)
    public double[] medianSlidingWindow(int[] nums, int k) {
        Comparator<Integer> comparator = (a, b) -> nums[a] != nums[b] ? Integer.compare(nums[a], nums[b]) : a - b;
        TreeSet<Integer> minSet = new TreeSet<>(comparator);
        TreeSet<Integer> maxSet = new TreeSet<>(comparator.reversed());
        int n = nums.length - k + 1;
        if (n <= 0) return new double[0];
        double[] ret = new double[n];
        for (int i=0; i<k-1; i++) {
            maxSet.add(i);
        }
        balance(maxSet, minSet);
        for (int i=k-1, r=0; i<nums.length; i++, r++) {
            minSet.add(i);
            maxSet.add(minSet.pollFirst());
            balance(maxSet, minSet);
            ret[r] = getMedian(maxSet, minSet, nums);
            if (!maxSet.remove(i-k+1)) {
                minSet.remove(i-k+1);
            }
        }
        return ret;
    }
    
    private double getMedian(TreeSet<Integer> maxSet, TreeSet<Integer> minSet, int[] nums) {
        if (maxSet.isEmpty() && minSet.isEmpty()) return 0;
        if (maxSet.size() == minSet.size()) {
            return ((double)nums[maxSet.first()] + nums[minSet.first()])/2;
        } else {
            return (double) nums[minSet.first()];
        }
    }
    
    private void balance(TreeSet<Integer> maxSet, TreeSet<Integer> minSet) {
        while (maxSet.size() > minSet.size()) {
            minSet.add(maxSet.pollFirst());
        }
    }
}
__________________________________________________________________________________________________
