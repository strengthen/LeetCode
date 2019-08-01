__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    
    class Node {
        public int l;
        public int r;
        public int max;
        public int height;
        public Node left;
        public Node right;
        
        public Node (int l, int r, int max, int height) {
            this.l = l;
            this.r = r;
            this.max = max;
            this.height = height;
        }
    }
    
    
    private boolean intersect(Node n, int l, int r) {
        if (r <= n.l || l >= n.r) {
            return false;
        }
        return true;
    }
    
    private Node insert(Node root, int l, int r, int height) {
        if (root == null) {
            return new Node(l, r, r, height);
        }
        
        if (l <= root.l) {
            root.left = insert(root.left, l, r, height);
        } else {
             // l > root.l
            root.right = insert(root.right, l, r, height);
        }
        root.max = Math.max(r, root.max);
        return root;
    }
    
    // return the max height for interval (l, r)
    private int maxHeight(Node root, int l, int r) {
        if (root == null || l >= root.max) {
            return 0;
        }
        
        int res = 0;
        if (intersect(root, l, r)) {
            res = root.height;
        }
        if (r > root.l) {
            res = Math.max(res, maxHeight(root.right, l, r));
        }
        res = Math.max(res, maxHeight(root.left, l, r));
        return res;
    }
    
    public List<Integer> fallingSquares(int[][] positions) {
        Node root = null;
        List<Integer> res = new ArrayList<>();
        int prev = 0;
        
        for (int i = 0; i < positions.length; ++i) {
            int l = positions[i][0];
            int r = positions[i][0] + positions[i][1];
            int currentHeight = maxHeight(root, l, r);
            root = insert(root, l, r, currentHeight + positions[i][1]);
            prev = Math.max(prev, currentHeight + positions[i][1]);
            res.add(prev);
        }
        
        return res;
    }
}
__________________________________________________________________________________________________
sample 37168 kb submission
class Solution {
  private int maxHeight = 0;
  private TreeMap<Integer, Integer> map = new TreeMap<>();

  private int max(Map<Integer, Integer> m) {
    int[] mx = {0};
    m.forEach((k, v) -> mx[0] = Math.max(mx[0], v));
    return mx[0];
  }
  private void update(int start, int end, int height) {
    map.put(start, map.floorEntry(start).getValue());
    map.put(end, map.floorEntry(end).getValue());
    
    Map<Integer, Integer> sub = map.subMap(start, end);
    height += max(sub);
    //height += sub.values().stream().max(Integer::compare).get();
    //height += sub.values().stream().mapToInt(a -> a).max().getAsInt();
    sub.clear();
    map.put(start, height);
    maxHeight = Math.max(maxHeight, height);
  }
  public List<Integer> fallingSquares(int[][] positions) {
    map.put(Integer.MIN_VALUE, 0);
    List<Integer> ans = new ArrayList<>();
    for (int[] pos : positions) {
      int start = pos[0];
      int height = pos[1];
      int end = start + height;
      update(start, end, height);
      ans.add(maxHeight);
    }
    return ans;
  }
}
__________________________________________________________________________________________________
