__________________________________________________________________________________________________
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
    int ma = 0;
    int ct = 0;
    TreeNode tp = null;
    HashMap<TreeNode,Integer> mp = new HashMap<>();
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        g(root,0);
        if(ct==1){
            return tp;
        }
        return g1(root);
        
    }
    
    public TreeNode g1(TreeNode r){
        if(r==null) return null;
        
        if(r.left!=null&&r.right==null){
            return g1(r.left);
        }else if(r.right!=null&&r.left==null){
            return g1(r.right);
        }else if(r.left!=null&&r.right!=null){
            
            if(mp.get(r.left)==mp.get(r.right)){
                return r;
            }else if(mp.get(r.left)<mp.get(r.right)){
                return g1(r.right);
            }else{
                return g1(r.left);
            }
            
            
        }else{
            return r;
        }
       // return r;
    }
    
    
    public int g(TreeNode r,int d){
        if(r==null) return d-1;
        if(d>ma){
            ma = d;
            ct = 1;
            tp = r;
        }else if(d==ma){
            ct++;
        }
        
        int le = g(r.left,d+1);
        int ri = g(r.right,d+1);
        
        int md = Math.max(le,ri);
        mp.put(r,md);
        return md;
    }
}

__________________________________________________________________________________________________

__________________________________________________________________________________________________
