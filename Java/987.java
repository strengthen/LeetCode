__________________________________________________________________________________________________
sample 2 ms submission
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private HashMap<Integer, PriorityQueue<int[]>> map = new HashMap<>();
    private int min = 1000, max = 0;
    
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        walk(root, 1000, 1000);
        
        List<List<Integer>> result = new LinkedList<>();
        for (int i = min; i <= max; i++) {
            PriorityQueue<int[]> temp = map.get(i);
            List<Integer> res = new LinkedList<>();
            while (!temp.isEmpty()) {
                res.add(temp.poll()[1]);
            }
            result.add(res);
        }
        
        return result;
    }
    
    private void walk(TreeNode root, int x, int y) {
        if (root == null)
            return;
        
        min = Math.min(min, x);
        max = Math.max(max, x);
        PriorityQueue<int[]> temp = map.getOrDefault(x, new PriorityQueue<int[]>(new Comparator<int[]> () {
            public int compare(int[] a1, int[] a2) {
                return a1[0] != a2[0] ? a2[0] - a1[0] : a1[1] - a2[1];
            }
        }));
        temp.offer(new int[]{y, root.val});
        map.put(x, temp);
        
        walk(root.left, x-1, y-1);
        walk(root.right, x+1, y-1);
    }
}
__________________________________________________________________________________________________
sample 37028 kb submission
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
  
  List<Location> locations;
  
  public List<List<Integer>> verticalTraversal(TreeNode root) {
    locations = new ArrayList<>();
    DFS(root, 0, 0);
    Collections.sort(locations);
    
    List<List<Integer>> result = new ArrayList<>();
    int x_coordinate = locations.get(0).x;
    result.add(new ArrayList<>());
    
    for (Location location : locations) {
      // Next index
      if (x_coordinate != location.x) {
        x_coordinate = location.x;
        result.add(new ArrayList<>());
      }
      result.get(result.size()-1).add(location.val);
    }
    return result;
  }
  
  private void DFS(TreeNode node, int x, int y) {
    if (node == null) {
      return;
    }
    locations.add(new Location(x, y, node.val));
    DFS(node.left, x-1, y+1);
    DFS(node.right, x+1, y+1);
  }
}

class Location implements Comparable<Location> {
  int x;
  int y;
  int val;
  
  Location(int x, int y, int val) {
    this.x = x;
    this.y = y;
    this.val = val;
  }
  
  @Override
  public int compareTo(Location theOther) {
    if (x != theOther.x) {
      return Integer.compare(x, theOther.x);
    } else if (this.y != theOther.y) {
      return Integer.compare(y, theOther.y);
    } else {
      return Integer.compare(val, theOther.val);
    }
  }
}
__________________________________________________________________________________________________
