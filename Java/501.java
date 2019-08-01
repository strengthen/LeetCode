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
    int max = 0;
    int counter = 1;
    TreeNode prev = null;
    
    public int[] findMode(TreeNode root) {
        List<Integer> result = new ArrayList<>(); 
        
        inOrder(root, result);
        
        if(result.size() < 1)
            return new int[0];
        
        int[] ans = new int[result.size()];
        
        for(int i = 0; i < result.size(); i++){
            ans[i] = result.get(i);
        }
        
        return ans;
        
    }
    
    
    public void inOrder(TreeNode root, List<Integer> result){
        
        if(root == null)
            return;
        
        inOrder(root.left, result);
        
        if(prev != null){
            if(prev.val == root.val)
                counter++;
            else{
                counter = 1;
            }
        }
         
        prev = root;
        
        if(counter > max){
            result.clear();
            result.add(root.val);
            max = counter;
            
        }else if(counter == max){
            result.add(root.val);
        }
        
        inOrder(root.right, result);     
    }   
}
__________________________________________________________________________________________________
sample 37884 kb submission
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    private int currVal;
    private int currCount = 0;
    private int maxCount = 0;
    private int modeCount = 0;
    
    ArrayList<Integer> modes;
    
    public int[] findMode(TreeNode root) {
        inorder(root, false);
        modes = new ArrayList<>();
        maxCount = Math.max(maxCount, currCount);
        modeCount = 0;
        currCount = 0;
        System.out.println(maxCount);
        inorder(root, true);
        int[] mode = new int[modes.size()];
        int i =0;
        for(int n: modes)
            mode[i++] = n;
        return mode;
    }

    

    private void handleValue(int val, boolean flag) {
        if(flag)
        {
            if(currVal != val)
            {
                currVal = val;
                currCount = 0;
            }
            currCount ++;
            if(currCount == maxCount)
                {
                    modes.add(currVal);     
                }
        }
        else
        {
            if(val != currVal)
            {
                maxCount = Math.max(maxCount, currCount);
                currVal = val;
                currCount = 0;
            }
            currCount ++;
        }
       
    }
    
    private void inorder(TreeNode root, boolean flag) {
        if (root == null) return;
        inorder(root.left, flag);
        handleValue(root.val, flag);
        inorder(root.right, flag);
    }
}
__________________________________________________________________________________________________
