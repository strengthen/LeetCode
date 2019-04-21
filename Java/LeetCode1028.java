__________________________________________________________________________________________________
1ms
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
    
    int idx =0;
    public TreeNode recoverFromPreorder(String s) {
        if (s==null || s.length()==0) return null;
        char[] arr = s.toCharArray();
        return generate( arr, 0 );
    }
    
    public TreeNode generate(char[] arr, int depth) {
        //NOTE: add null for last node leaf 
        if (idx == arr.length) return null;
        
        int curDepth =0, tmp=idx;
        while (tmp< arr.length && arr[tmp]=='-' ) {
            curDepth++;
            tmp++;
        }
        
        //NOTE: add null for leaf   curDepth==0 is root 
        if (curDepth!=0 && depth >= curDepth) {
            return null; 
        }
        
        int num=0; idx =tmp;
        while (idx< arr.length && Character.isDigit(arr[idx]) ) {
            num = num*10 + (arr[idx]-'0');
            idx++;
        }

        TreeNode root = new TreeNode(num);
        root.left = generate(arr, curDepth);
        root.right = generate(arr, curDepth);
        return root;
    }    
}
__________________________________________________________________________________________________
2ms
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
    int dashes = 0;
    int start = 0;
    public TreeNode recoverFromPreorder(String S) {
        return helper(S, 0);
    }
    
    private TreeNode helper(String s, int level) {
        int val = 0;
        while (start < s.length() && s.charAt(start) != '-') {
            val = val * 10 + (s.charAt(start) - '0');
            start ++;
        }
        TreeNode root = new TreeNode(val);

        while(start < s.length() && s.charAt(start) == '-') {
            dashes ++;
            start ++;
        }
        if (dashes == level + 1) {
            dashes = 0;
            root.left = helper(s, level + 1);
            if (dashes == level + 1) {
                dashes = 0;
                root.right = helper(s, level + 1);
            }
        }
        return root;
    }
}
__________________________________________________________________________________________________
3ms
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
    public TreeNode recoverFromPreorder(String S) {
        return helper(S, 0, S.length(), 0);
    }
  
  TreeNode helper(String s, int start, int end, int d) {
    int v = getInt(s, start + d);
    TreeNode r = new TreeNode(v);
    int ls = find(s, start, end, d + 1);
    if (ls == -1) {
      return r;
    } else {
      int rs = find(s, ls + d + 1, end, d + 1);
      if (rs == -1) {
        r.left = helper(s, ls, end, d + 1);
      } else {
        r.left = helper(s, ls, rs, d + 1);
        r.right = helper(s, rs, end, d + 1);
      }
      return r;
    }
  }
  
  int find(String s, int start, int end, int d) {
    int count = 0;
    while (start < end) {
      if (s.charAt(start) == '-') {
        count++;
      } else {
        if (d == count) {
          return start - count;
        }
        count = 0;
      }
      start++;
    }
    return -1;
  }
  
  private int getInt(String s, int i) {
    int res = 0;
    while (i < s.length() && s.charAt(i) != '-') {
      res = res * 10 + s.charAt(i) - '0';
      i++;
    }
    return res;
  }
}
__________________________________________________________________________________________________
4ms
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
    public int index;
    public int getLevel(String S, int current){
        int count = 0;
        while(current < S.length() && S.charAt(current) == '-'){
            count++;
            current++;
        }
        return count;
    }

    public TreeNode help(String S, int level) {
        TreeNode root = null;
        if(index >= S.length()) return root;
        int currentL = getLevel(S,index);
        if(currentL == level){
            index = index + currentL;
            int num = 0;
            while(index < S.length() && Character.isDigit(S.charAt(index)) ){
                num = num*10 + S.charAt(index) - '0';
                index++;
            }
            root = new TreeNode(num);
            root.left = help(S,level+1);
            root.right = help(S,level+1);
        }
        return root;
    }
    public TreeNode recoverFromPreorder(String S) {
        index = 0;
        return help(S,0);
    }
}
__________________________________________________________________________________________________
5ms
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
    public TreeNode recoverFromPreorder(String S) {
        
        if(S == null || S.length() == 0) return null;        
        int depth = -1 , pd = -1 ,i = 0;        
        TreeNode root = null;        
        Deque<TreeNode> stack = new ArrayDeque<>();        
        TreeNode current = root;       
        
        while(i < S.length()){
            pd = depth;
            depth = 0;            
            while(S.charAt(i) == '-'){
                depth++; i++;
            }            
            int tmp = S.indexOf('-' , i);               
             tmp = tmp == -1 ? S.length(): tmp;               
            int value = Integer.parseInt(S.substring(i , tmp ));
            i = tmp;            
            TreeNode n = new TreeNode(value);
            if(current == null){
                current = n;
                root = current;
            }else{
                if(depth > pd){
                    current = stack.peek();
                    current.left = n;                  
                }else{
                    int diff = pd - depth+1;
                    
                    while(diff >0){
                        current = stack.pop(); diff--;
                    }                    
                    current = stack.peek();
                    current.right = n;                  
                }
            }            
            stack.push(n);
        }        
        return root;         
    }
}
__________________________________________________________________________________________________
7ms
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
    public TreeNode recoverFromPreorder(String S) {        
        // Store our node in a stack.
        // For every node, count the dashes to determine the depth.
        // Pop the stack until the size of the stack matches the depth.
        // The parent will be the top of the stack.
        // Once a node is popped of the stack, we don't need it anymore.
        LinkedList<TreeNode> stack = new LinkedList<>();
        
        int i = 0;
        while(i < S.length()) {
            
            // Count the dashes to figure out the depth.
            int depth = 0;
            while(S.charAt(i) == '-') {
                ++i;
                ++depth;
            }
            
            // Calculate the current number.
            int number = 0;
            while(i < S.length() && S.charAt(i) != '-') {
                number = 10*number + Character.getNumericValue(S.charAt(i));
                ++i;
            }
            
            TreeNode node = new TreeNode(number);
            
            // Handle the root node.
            if(depth == 0) {
                stack.push(node);
                continue;
            }
            
            // Not the root node.
            // Keep popping the stack until we get to the parent.
            // We won't need any of the nodes that we've popped.
            while(stack.size() > depth) {
                stack.pop();
            }
            
            TreeNode parent = stack.peek();
            if(parent.left == null) {
                parent.left = node;
            } else {
                parent.right = node;
            }
            
            // Add our new node to the top of the stack.
            stack.push(node);
        }
        
        // The root is at the bottom of the stack.
        // Get it and return it.
        while(stack.size() > 1) {
          stack.pop();
        }
        return stack.pop();
    }
}
__________________________________________________________________________________________________