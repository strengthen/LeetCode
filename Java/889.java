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
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        return helper(pre, post, 0, pre.length-1, 0, post.length-1);
    }
    
    private TreeNode helper(int[] pre, int[] post, int el, int er, int ol, int or){
        if(el > er || ol > or) return null;
        TreeNode node = new TreeNode(pre[el]);
        el++;
        or--;
        int r = or;
        while(r > ol && post[r] != pre[el]) r--;
        node.left = helper(pre, post, el, el+(r-ol), ol, r);
        node.right = helper(pre, post, el+(r-ol)+1, er, r+1, or);
        return node;
    }
}
__________________________________________________________________________________________________
sample 36752 kb submission
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
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        
        int N = pre.length;
        if(N==0){
            return null;
        }
        
        TreeNode root = new TreeNode(pre[0]);
        
        if(N==1){return root;}
        
        int L=0;
        
        for(int i=0; i<N; i++){
            if(post[i] == pre[1]){
                L = i+1;
            }
        }
        
        root.left = constructFromPrePost(Arrays.copyOfRange(pre, 1, L+1), Arrays.copyOfRange(post, 0, L));
        
        root.right = constructFromPrePost(Arrays.copyOfRange(pre, L+1, N), Arrays.copyOfRange(post, L, N-1));
        
        return root;
    }
}
__________________________________________________________________________________________________
