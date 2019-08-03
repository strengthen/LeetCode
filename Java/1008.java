__________________________________________________________________________________________________
sample 0 ms submission
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
    
    int i = 0;
    
    public TreeNode bstFromPreorder(int[] preorder) {
       return bstHelper(preorder, Integer.MAX_VALUE); 
    }
    
    private TreeNode bstHelper(int[] preorder, int maxValue) {

        if (i == preorder.length || preorder[i] > maxValue) {
            return null;
        }

        TreeNode rootNode = new TreeNode(preorder[i++]);
        rootNode.left = bstHelper(preorder, rootNode.val);
        rootNode.right = bstHelper(preorder, maxValue);

        return rootNode;
    }
}
__________________________________________________________________________________________________
sample 34968 kb submission
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
    public TreeNode bstFromPreorder(int[] preorder) {
        List<Integer> all = Arrays.stream(preorder)
							  .boxed()
							  .collect(Collectors.toList());
		TreeNode head = new TreeNode(preorder[0]);
		head.left = getChild(getSmallArray(all));
		head.right = getChild(getBigArray(all));
        
        return head;
    }
    
    private static TreeNode getChild(List<Integer> preorder) {
		if(preorder.size() == 0){
			return null;
		}
		TreeNode child = new TreeNode(preorder.get(0));
		child.left = getChild(getSmallArray(preorder));
		child.right = getChild(getBigArray(preorder));
		return child;
	}

	private static List<Integer> getBigArray(List<Integer> preorder) {
		if(preorder.size() == 0){
			return null;
		}
		int head = preorder.get(0);
		return preorder.stream()
					   .filter(num -> num > head)
					   .collect(Collectors.toList());
	}

	private static List<Integer> getSmallArray(List<Integer> preorder) {
		if(preorder.size() == 0){
			return null;
		}
		int head = preorder.get(0);
		return preorder.stream()
					   .filter(num -> num < head)
					   .collect(Collectors.toList());
	}
}
__________________________________________________________________________________________________
