__________________________________________________________________________________________________
sample 1 ms submission
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
    
    private Map<Integer, List<TreeNode>> cache = new HashMap<>();
    
    public List<TreeNode> allPossibleFBT(int N) {
        if (cache.containsKey(N)) {
			return cache.get(N);
		}
		List<TreeNode> nodeList = new ArrayList<TreeNode>();
		if (N == 1) {
			nodeList.add(new TreeNode(0));
		} else {
			for (int i = 1; i < N / 2 + 1; i = i + 2) {
				List<TreeNode> leftList = allPossibleFBT(i);
				List<TreeNode> rightList = allPossibleFBT(N - 1 - i);
				for (TreeNode left : leftList) {
					for (TreeNode right : rightList) {
						TreeNode node = new TreeNode(0);
						node.left = left;
						node.right = right;
						nodeList.add(node);
						if (i < N - 1 - i) {
							node = new TreeNode(0);
							node.left = right;
							node.right = left;
							nodeList.add(node);
						}
					}
				}
			}
		}
		cache.put(N, nodeList);
		return nodeList;
    }    
}
__________________________________________________________________________________________________
sample 43520 kb submission
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
    public List<TreeNode> allPossibleFBT(int N) {
        if (N % 2 == 0) return new ArrayList<TreeNode>();
        List<List<TreeNode>> arrayList = new ArrayList<List<TreeNode>>();
      
        TreeNode root =new TreeNode(0);
        List<TreeNode> list = new ArrayList<>();
        list.add(root);
        arrayList.add(list);
        //System.out.println(arrayList.get(0));
        for (int i = 3; i < N+1; i=i+2) {
            List<TreeNode> list1 = new ArrayList<TreeNode>();
            int left = i-1;
            for (int r = 1; r < left; r= r+2) {
                
                for (TreeNode nodeLeft: arrayList.get(r/2)) {
                    
                    for (TreeNode nodeRight: arrayList.get((left-r)/2)) {
                        TreeNode root1 =new TreeNode(0);
                        root1.left = nodeLeft;
                        root1.right = nodeRight;
                        list1.add(root1);
                    }
                }
            }
            arrayList.add(list1);
        }
        return arrayList.get(N/2);
    }
}
__________________________________________________________________________________________________
