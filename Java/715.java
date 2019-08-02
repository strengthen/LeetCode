__________________________________________________________________________________________________
sample 67 ms submission
class RangeModule {
    // https://leetcode.com/problems/range-module/discuss/245463/Beat-100-Java-Binary-Search-Tree-implementation-short-and-concise
    
    private class TreeNode {
        int start;
        int end;
        TreeNode left;
        TreeNode right;
        TreeNode(int s, int e) {
            start = s;
            end = e;
            left = null;
            right = null;
        }
    }

    TreeNode root;
    public RangeModule() {
        root = null;
    }
    
    public void addRange(int left, int right) {
        root = insert(root, left, right);
    }
    
    private TreeNode insert(TreeNode node, int start, int end) {
        if (start >= end) {
            return node;
        }
        
        if (node == null) {
            return new TreeNode(start, end);
        }
        
        if (end < node.start) {
            node.left = insert(node.left, start, end);
        } else if (start >= node.end) {
            node.right = insert(node.right, start, end);
        } else {
            // node: [5, 10]; there are 4 case:
            // 1. [3, 12] 3, 5; 10, 15
            // 2. [6, 9] 6, 5; 10, 9
            // 3. [6, 11] 6, 5; 10, 11
            // 4. [3, 7] 3, 5; 10, 7
            node.left = insert(node.left, start, node.start);
            node.right = insert(node.right, node.end, end);
        }
        return node;
    }
    
    public boolean queryRange(int left, int right) {
        return search(root, left, right);
    }
    
    private boolean search(TreeNode node, int start, int end) {
        if (start >= end) {
            return true;
        }

        if (node == null) {
            return false;
        }

        if (end < node.start) {
            return search(node.left, start, end);
        } else if (start >= node.end) {
            return search(node.right, start, end);
        } else {
            // no need to check start >= root.start && end <= root.end, which is covered by recursive base rule (start >= end)
            // node: [5, 10]; there are 4 case:
            // 1. [3, 12] 3, 5; 10, 15
            // 2. [6, 9] 6, 5; 10, 9 => true
            // 3. [6, 11] 6, 5; 10, 11
            // 4. [3, 7] 3, 5; 10, 7
            return search(node.left, start, node.start) && search(node.right, node.end, end);
        }
    }
    
    public void removeRange(int left, int right) {
        root = removeRange(root, left, right);
    }
    
    private TreeNode removeRange(TreeNode root, int start, int end) {
        if (start >= end || root == null) {
            return root;
        }
        
        if (end < root.start) {
            root.left = removeRange(root.left, start, end);
        } else if (start >= root.end) {
            root.right = removeRange(root.right, start, end);
        } else {
            root.left = removeRange(root.left, start, root.start);
            root.right = removeRange(root.right, root.end, end);
            root.left = insert(root.left, root.start, start);
            root.right = insert(root.right, end, root.end);
            root = removeNode(root);
        }
        return root;
    }
    
    private TreeNode removeNode(TreeNode node) {
        if (node == null) {
            return null;
        }
        if (node.left == null) {
            return node.right;
        }
        TreeNode leftLargest = getLargest(node.left, node);
        leftLargest.left = node.left;
        leftLargest.right = node.right;
        return leftLargest;
    }
    
    private TreeNode getLargest(TreeNode node, TreeNode parent) {
        while (node.right != null) {
            parent = node;
            node = node.right;
        }
        if (node == parent.left) {
            parent.left = node.left;
        } else if (node == parent.right) {
            parent.right = node.left;
        }
        node.left = null;
        return node;
    }
}

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * boolean param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
__________________________________________________________________________________________________
sample 56660 kb submission
class RangeModule {
    TreeMap<Integer, Integer> map;
    public RangeModule() {
        map = new TreeMap<>();
    }
    
    public void addRange(int left, int right) {
        Integer start = map.floorKey(left);
        if( start == null) start = map.ceilingKey(left);
        while(start != null && start<=right)
        {
            int end = map.get(start);
            if(end>=left)
            {
                map.remove(start);
                left = Math.min(left, start);
                right = Math.max(right, end);
            }
            start = map.ceilingKey(end);
        }
        map.put(left, right);
    }
    
    public boolean queryRange(int left, int right) {
        Integer floor = map.floorKey(left);
        return floor != null && map.get(floor) >= right;
    }
    
    public void removeRange(int left, int right) {
        Integer start = map.floorKey(left);
        if(start == null) start = map.ceilingKey(left);
        while(start != null && start < right)
        {
            int end = map.get(start);
            if(end >= left)
            {
                map.remove(start);
                if(left>start) map.put(start, left);
                if(end>right) map.put(right, end);
            }
            start = map.ceilingKey(end);
        }
    }
}

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * boolean param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
__________________________________________________________________________________________________
